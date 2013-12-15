#ifndef BRUCHSTIICK
#define BRUCHSTIICK

#include <QMainWindow>

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "image.h"

#include "calcShards.h"

class QAction;
class QMenu;
class QLabel;
class QScrollArea;
class QPushButton;
class QLineEdit;
class QTextEdit;
class QSlider;
class QProgressBar;
class QComboBox;

class BruchstIIck : public QMainWindow
{
	Q_OBJECT

public:
	BruchstIIck();

private slots:

	void load();
	void save();

	void handle_mean_filter();
	void handle_median_filer();
	void handle_laplacian_filter();
	void handle_laplacianW_filter();
	void handle_sobel_filter();
	void handle_scharr_filter();
	void handle_kirsch_filter();
	void handle_roberts_filter();
	void handle_light_add();
	void handle_light_sub();
	void handle_invert_filter();
	void handle_global_threshold_filter();
	void handle_set_border_filter();
	void handle_custom_filter();
	void handle_undo_button();
	void handle_calcShards();
	void handle_edge_detecter_combo(int i);
	void handle_global_contrast();
	void handle_gamma_patch();

	void handle_load_program();
	void handle_save_program();
	void handle_run_program();
	void handle_clear_program();
	void handle_pop_program();

	void handle_threshold_slider();

	void handle_message_about();

private:
	CCalcShards* ccalcShards;
	QImage m_image_org_org;
	std::vector<QImage> images;
	std::vector<std::string> m_program;

	void createMenus();
	void createActions();
	void createHistogram();
	void addToProgram(std::string param);

	QLabel* m_imageOrg;
	QLabel* m_imageMod;
	QLabel* m_histogram;
	QLabel* m_image_infos;
	QLabel* m_slider_pos;

	QPushButton* m_mean_button;
	QPushButton* m_median_button;
	//QPushButton* m_laplacian_button;
	QPushButton* m_laplacianW_button;
	//QPushButton* m_sobel_button;
	//QPushButton* m_scharr_button;
	//QPushButton* m_kirsch_button;
	//QPushButton* m_roberts_button;
	QPushButton* m_light_add_button;
	QPushButton* m_light_sub_button;
	QPushButton* m_global_contrast_button;
	QPushButton* m_gamma_patch_button;
	QPushButton* m_invert_button;
	QPushButton* m_set_threshold_button;
	QPushButton* m_set_border_button;
	QPushButton* m_custom_button;
	QPushButton* m_undo_button;
	QPushButton* m_calcShards_button;

	QPushButton* m_save_program_button;
	QPushButton* m_load_program_button;
	QPushButton* m_run_program_button;
	QPushButton* m_clear_program_button;
	QPushButton* m_pop_program_button;

	QComboBox*   m_edge_detector_combo;
	
	QProgressBar* m_prog_progress;

	QTextEdit* m_program_edit;

	QLineEdit* m_mean_edit;
	QLineEdit* m_median_edit;
	QLineEdit* m_laplacianW_edit;
	QLineEdit* m_border_width_edit;
	QLineEdit* m_custom_edit;

	QLineEdit* m_g_contrast_min_edit;
	QLineEdit* m_g_contrast_max_edit;

	QLineEdit* m_gamma_patch_max_edit;
	QLineEdit* m_gamma_patch_gamma_edit;

	QSlider* m_threshold_slider;

	QAction* m_load_action;
	QAction* m_save_action;
	QAction* m_close_action;

	QAction* m_load_prog_action;
	QAction* m_save_prog_action;
	QAction* m_run_prog_action;
	QAction* m_clear_prog_action;
	QAction* m_pop_program_action;
	QAction* m_message_about_action;
	

	QMenu* m_file_Menu;
	QMenu* m_program_Menu;
	QMenu* m_help_Menu;
};

#endif
