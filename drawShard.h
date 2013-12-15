#ifndef DRAWSHARD_H
#define DRAWSHARD_H

#include <QMainWindow>
#include "image.h"

class QLabel;

class CDrawShard : public QMainWindow
{
private:
	std::list<SShard>* m_list;
	int					 m_index;
	QImage*				 m_image;
	QImage*				 m_image_org;
	QImage*				 m_shard_image;
	QImage*				 m_shard_image_org;
	SShard				 m_shard;
public:
	CDrawShard(std::list<SShard>* l, 
				  int index,
				  QImage* image,
				  QImage* image_org);
private slots:

	QLabel* m_shard_label;
	QLabel* m_shard_org_label;
};

#endif
