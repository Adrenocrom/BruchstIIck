#include <QtGui>
#include <QColor>

#include "drawShard.h"

CDrawShard::CDrawShard(std::list<SShard>* l,
							  int index,
							  QImage* image,
							  QImage* image_org)
{
	setMinimumSize(542, 300);
	setMaximumSize(542, 300);	

	setStyleSheet(QString("QMainWindow{background-color: #ffffff; border: 1px solid #000000;}")+
					  QString("QMenuBar{background-color: #444444; color: #FFFFFF;}")+
					  QString("QMenuBar::item{background-color: #444444; color: #FFFFFF;}")+
					  QString("QMenuBar::item:selected{background-color: #333333; color: #FFFFFF}")+
					  QString("QMenu{background-color: #444444; color: #FFFFFF; selection-color: #FFFFFF; selection-background-color: #333333;}")+
					  QString("QLabel{color: #FFFFFF; border: 1px solid #000000; background-color: #222222}")+
					  QString("QPushButton{color: #FFFFFF; background-color: #222222; border-radius: 5px;}")+
					  QString("QLineEdit{background-color: #DDDDDD; border-radius: 2px; border: 1px solid #000000;}")+
					  QString("QTextEdit{background-color: #DDDDDD; border-radius: 2px; border: 1px solid #000000;}")+
					  QString("QSlider{background-color: #FFFFFF; color: #FFFFFF; border-style: none;}")+
					  QString("QSlider::handle{background: #222222; border: 1px solid #FFFFFF; width: 5px;}")+
					  QString("QProgressBar{border-radius: 2px; border: 1px solid #000000; color:#000000;text-align: center;}")+
					  QString("QProgressBar::chunk{width: 10px; background-color: #22AA33}"));

	m_list = l;
	m_index = index;
	m_image = image;
	m_image_org = image_org;

	std::list<SShard>::iterator it;
	int cnt = 0;
	for(it = (*m_list).begin(); it != (*m_list).end(); ++it) {
		if(cnt == index) {
			m_shard = *it;
			break;
		}

		cnt++;
	}

	SVector2 OBBMin = m_shard.OBB.first;
	SVector2 OBBMax = m_shard.OBB.second;
	OBBMin.x /= 2; OBBMin.y /= 2;
	OBBMax.x /= 2; OBBMax.y /= 2;

	int h = (OBBMax.y - OBBMin.y) + 2;
	int w = (OBBMax.x - OBBMin.x) + 2;

	m_shard_image = new QImage(w, h, QImage::Format_RGB32);
	m_shard_image_org = new QImage(w, h, QImage::Format_RGB32);

	for(int y = 0; y < m_shard_image->height(); ++y) {
		for(int x = 0; x < m_shard_image->width(); ++x) {
			int X = x + OBBMin.x-1;
			int Y = y + OBBMin.y-1;
			
			if(X < 0 || Y < 0 || X >= m_image->width() || Y >= m_image->height()) {
				m_shard_image->setPixel(x, y, qRgb(0, 0, 0));
				m_shard_image_org->setPixel(x, y, qRgb(0, 0, 0));
			} 
			else {
				m_shard_image->setPixel(x, y, m_image->pixel(X, Y));
				m_shard_image_org->setPixel(x, y, m_image_org->pixel(X, Y));
			}
		}
	}

	m_shard_label = new QLabel("", this);
	m_shard_label->setGeometry(QRect(QPoint(10, 10), QSize(256, 256)));
	m_shard_label->setPixmap(QPixmap::fromImage(*m_shard_image).scaled(256, 256));

	m_shard_org_label = new QLabel("", this);
	m_shard_org_label->setGeometry(QRect(QPoint(276, 10), QSize(256, 256)));
	m_shard_org_label->setPixmap(QPixmap::fromImage(*m_shard_image_org).scaled(256, 256));
}
