#include <QtGui>

#include "calcWorker.h"

CCalcWorker::CCalcWorker(int id, 
								 QWidget* parent, 
								 std::vector<SShard>* shards, 
								 QImage image)
{ 
	m_Id 		= id;
	m_shards = shards;
	m_image  = image;
	m_parent = parent;
	m_isWorking = true;
}

void CCalcWorker::work()
{
	int iNumChunkShards = (*m_shards).size();
	CImage* src = new CImage(&m_image);
	int value = 0;

	
	for(int i = 0; i < iNumChunkShards; i++) {
		(*m_shards)[i].boundary = src->calcBoundary((*m_shards)[i].x,
																  (*m_shards)[i].y,
																  (*m_shards)[i].iColor);

		(*m_shards)[i].dss = src->createDSS((*m_shards)[i].boundary);

		(*m_shards)[i].U = src->getLengthFromDSS((*m_shards)[i].dss);

		(*m_shards)[i].OBB = src->getOBBFromShard((*m_shards)[i].boundary);

		value = i+1;
		emit valueChanged(value);
		m_parent->update();
	}

	delete src;
	m_isWorking = false;
	emit finished();
}
