#ifndef CALCSHARDS
#define CALCSHARDS

#include <QMainWindow>

#include "image.h"
#include "calcWorker.h"
#include "drawShard.h"

#define NUM_CHUNKS 10

class QLabel;
class QAction;
class QMenu;
class QPushButton;
class QTableWidget;
class QProgressBar;
class QGroupBox;

bool compare_area(SShard first, SShard second);

class CCalcShards : public QMainWindow
{
	Q_OBJECT

public:
	CCalcShards(QImage image, QImage orgImage);
	
private slots:
	
	void handle_create_shards();
	void handle_color_shard(int y, int x);
	void handle_clear_color();
	void handle_draw_shard(int y, int x);

	void handle_export();

	void handle_save_image();

private:
	bool flag;

	CDrawShard* drawShard;

	SVector2 m_temp_pos;
	QRgb 		m_temp_color;

	QLabel* m_image_label;
	QLabel* m_info_state_label;

	QLabel* m_num_shards_label;
	QLabel* m_smallest_label;
	QLabel* m_largest_label;

	QLabel* m_thread_label[NUM_CHUNKS];

	QPushButton* m_calc_shards_button;
	QPushButton* m_clear_color_button;
	
	QProgressBar* m_threads_progress[NUM_CHUNKS];

	QAction* m_close_action;
	QAction* m_export_action;
	QAction* m_import_action;
	QAction* m_load_image_action;
	QAction* m_save_image_action;

	QTableWidget* m_list_shards;

	QMenu* m_file_menu;

	void createMenu();
	void createActions();

	QImage* m_shardQImage;
	QImage* m_shardQImage_org;
	QImage* m_shardQImage_org_org;

	std::list<SShard>* m_shardList;
};

#endif
