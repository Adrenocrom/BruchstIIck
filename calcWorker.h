#ifndef CALCWORKER
#define CALCWORKER

#include <QObject>
#include <QMainWindow>

#include "image.h"

class QLabel;
class QProgressBar;

class CCalcWorker: public QObject
{
	Q_OBJECT

private:

	int						m_Id;
	std::vector<SShard>*	m_shards;
	QImage					m_image;
	QWidget*					m_parent;

public:

	bool m_isWorking;

	CCalcWorker(int id,
					QWidget* parent,
					std::vector<SShard>* shards,
					QImage image);

signals:

	void valueChanged(const int &value);
	void finished();

public slots:

	void work();
};

#endif
