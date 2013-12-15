#include <QtGui>

#include "calcShards.h"

bool compare_area(SShard first, SShard second)
{
	if(first.A > second.A)
		return true;
	return false;
}

CCalcShards::CCalcShards(QImage image, QImage orgImage)
{
	setMinimumSize(1000, 306 + (NUM_CHUNKS*30));
	setMaximumSize(1000, 306 + (NUM_CHUNKS*30));

	m_shardQImage_org_org = new QImage(orgImage);

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

	m_image_label = new QLabel(tr(""), this);
	m_image_label->setGeometry(QRect(QPoint(10, 30), QSize(256, 256)));
	m_image_label->setMinimumSize(256, 256);
	m_image_label->setMinimumSize(256, 256);
	m_image_label->setPixmap(QPixmap::fromImage(image).scaled(256, 256));

	QGroupBox* reporting = new QGroupBox(tr("reporting"), this);
	reporting->setGeometry(QRect(QPoint(276, 30), QSize(314, 256)));

	m_list_shards = new QTableWidget(this);
	m_list_shards->setGeometry(QRect(QPoint(600, 30), QSize(390, 266 + (NUM_CHUNKS*30))));
	QStringList header;
	header << "#" << "x" << "y" << "area" << "perimeter";
	m_list_shards->setColumnCount(5);
	m_list_shards->setColumnWidth(0,  50);
   m_list_shards->setColumnWidth(1,  65);
   m_list_shards->setColumnWidth(2,  65);
	m_list_shards->setColumnWidth(3,  90);
	m_list_shards->setColumnWidth(4,  100);
	m_list_shards->setHorizontalHeaderLabels(header);
	m_list_shards->verticalHeader()->setVisible(false);
	m_list_shards->setEditTriggers(QAbstractItemView::NoEditTriggers);
	connect(m_list_shards, SIGNAL(cellClicked(int, int)), this, SLOT(handle_color_shard(int, int)));
	connect(m_list_shards, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(handle_draw_shard(int, int)));

	m_clear_color_button = new QPushButton(tr("clear color"), this);
	m_clear_color_button->setGeometry(QRect(QPoint(510, 140), QSize(70, 20)));
	m_clear_color_button->setStyleSheet("background-color: #552222;");
	connect(m_clear_color_button, SIGNAL(released()), this, SLOT(handle_clear_color()));

	m_calc_shards_button = new QPushButton(tr("calc"), this);
	m_calc_shards_button->setGeometry(QRect(QPoint(286, 50), QSize(70, 20)));
	m_calc_shards_button->setStyleSheet("background-color: #225522;");
	connect(m_calc_shards_button, SIGNAL(released()), this, SLOT(handle_create_shards()));

	m_info_state_label = new QLabel(tr(""), this);
	m_info_state_label->setGeometry(QRect(QPoint(286, 256), QSize(294, 20)));
	m_info_state_label->setStyleSheet("background-color: #DDDDDD; border-radius: 2px; border: 1px solid #000000; color: #000000;");

	QLabel* num_shards_label = new QLabel(tr("number of shards"), this);
	num_shards_label->setGeometry(QRect(QPoint(390, 50), QSize(120, 20)));
	num_shards_label->setStyleSheet("background-color: #FFFFFF; color: #000000; border-style: none;");

	m_num_shards_label = new QLabel(tr(""), this);
	m_num_shards_label->setGeometry(QRect(QPoint(510, 50), QSize(70, 20)));
	m_num_shards_label->setStyleSheet("background-color: #DDDDDD; border-radius: 2px; border: 1px solid #000000; color: #000000;");

	QLabel* smallest_label = new QLabel(tr("size of smallest"), this);
	smallest_label->setGeometry(QRect(QPoint(390, 80), QSize(120, 20)));
	smallest_label->setStyleSheet("background-color: #FFFFFF; color: #000000; border-style: none;");

	m_smallest_label = new QLabel(tr(""), this);
	m_smallest_label->setGeometry(QRect(QPoint(510, 80), QSize(70, 20)));
	m_smallest_label->setStyleSheet("background-color: #DDDDDD; border-radius: 2px; border: 1px solid #000000; color: #000000;");

	QLabel* largest_label = new QLabel(tr("size of largest"), this);
	largest_label->setGeometry(QRect(QPoint(390, 110), QSize(120, 20)));
	largest_label->setStyleSheet("background-color: #FFFFFF; color: #000000; border-style: none;");

	m_largest_label = new QLabel(tr(""), this);
	m_largest_label->setGeometry(QRect(QPoint(510, 110), QSize(70, 20)));
	m_largest_label->setStyleSheet("background-color: #DDDDDD; border-radius: 2px; border: 1px solid #000000; color: #000000;");

	for(int i = 0; i < NUM_CHUNKS; ++i) {
		m_thread_label[i] = new QLabel(QString("thread ")+QString::number(i+1), this);
		m_thread_label[i]->setGeometry(QRect(QPoint(10, 306 + (i*30)), QSize(70, 20)));
		m_thread_label[i]->setStyleSheet("background-color: #FFFFFF; color: #000000; border-style: none;");		

		m_threads_progress[i] = new QProgressBar(this);
		m_threads_progress[i]->setGeometry(QRect(QPoint(90, 306 + (i*30)), QSize(500, 20)));
		m_threads_progress[i]->setRange(0, 100);
		m_threads_progress[i]->setValue(0);
	}

	m_shardQImage = new QImage(image);

	createActions();
	createMenu();

	flag = false;

	setWindowTitle("Vermessung");
}

void CCalcShards::createMenu()
{
	m_file_menu = new QMenu(tr("File"), this);
	m_file_menu->addAction(m_export_action);
	m_file_menu->addAction(m_import_action);
	m_file_menu->addSeparator();
	m_file_menu->addAction(m_save_image_action);
	m_file_menu->addSeparator();
	m_file_menu->addAction(m_close_action);

	menuBar()->addMenu(m_file_menu);
}

void CCalcShards::createActions()
{
	m_close_action = new QAction(tr("Close"), this);
	connect(m_close_action, SIGNAL(triggered()), this, SLOT(close()));

	m_export_action = new QAction(tr("Export results"), this);
	connect(m_export_action, SIGNAL(triggered()), this, SLOT(handle_export()));
	
	m_import_action = new QAction(tr("Import results"), this);

	m_save_image_action = new QAction(tr("Save image"), this);
	connect(m_save_image_action, SIGNAL(triggered()), this, SLOT(handle_save_image()));
}

void CCalcShards::handle_create_shards()
{
	m_info_state_label->setText("step 1/5: prepare counting ... ");

	CImage* src = new CImage(m_shardQImage);
	std::vector<SShard> shards;
	int iColor = 10;
	int cnt = 0;

	for(int y = 0; y < src->height; ++y) {
		QCoreApplication::processEvents();
		for(int x = 0; x < src->width; ++x) {
			if(src->pos[x][y] == 255) {
				SShard shard;
				shard.x = x;
				shard.y = y;
				shard.A = (float)src->flood4Fill(x, y, 255, iColor);
				shard.iColor = iColor;
				shards.push_back(shard);
				
				if(iColor >= 230)
					iColor = 10;
				else
					iColor += 10;

				cnt++;
																 
				m_info_state_label->setText(QString("step 2/5: counting ... (")+
													 QString::number(cnt) + QString(")"));
			}
		}
	}

	m_shardQImage = new QImage(src->get());
	m_image_label->setPixmap(QPixmap::fromImage(*m_shardQImage).scaled(256, 256));
	
	m_info_state_label->setText("step 3/5: prepare ...");
	int iNumShards = shards.size();
	m_num_shards_label->setText(QString::number(iNumShards));

	int iSmallest = INT_MAX;
	int iLargest  = INT_MIN;
	int tempA;

	std::vector<SShard>* vChunks[NUM_CHUNKS];
	for(int i = 0; i <  NUM_CHUNKS; ++i) {
		vChunks[i] = new std::vector<SShard>();
	}
	int iChunkSize = (int) ((float)(iNumShards/NUM_CHUNKS));
	int iChunk = 0;
	int iCnt = 0;
	SVector2 vChunkInterval[NUM_CHUNKS];
	vChunkInterval[0].x = 0;
	for(int i = 0; i < iNumShards; ++i) {
		QCoreApplication::processEvents();
		m_info_state_label->setText(QString("3/5: prepare ...(")+
											 QString::number(i+1)+QString("/")+
											 QString::number(iNumShards)+QString(")"));

		tempA = (int)shards[i].A;
		if(tempA < iSmallest)
			iSmallest = tempA;

		if(tempA > iLargest)
			iLargest = tempA;

		vChunks[iChunk]->push_back(shards[i]);

		iCnt++;
		if((iCnt >= iChunkSize) && (iChunk < NUM_CHUNKS-1)) {
			iCnt = 0;
			vChunkInterval[iChunk].y = i + 1;
			iChunk++;
			vChunkInterval[iChunk].x = i + 1;
		}
	}
	vChunkInterval[NUM_CHUNKS-1].y = iNumShards;

	m_smallest_label->setText(QString::number(iSmallest));
	m_largest_label->setText(QString::number(iLargest));

	QThread* threads[NUM_CHUNKS];

	CCalcWorker* worker[NUM_CHUNKS]; 
	QImage chunkImage = src->get();
	m_shardQImage = new QImage(chunkImage);
	m_shardQImage_org = new QImage(chunkImage);

	m_info_state_label->setText("step 4/5: prepare ...");

	for(int i = 0; i < NUM_CHUNKS; ++i) {
		QCoreApplication::processEvents();
		m_threads_progress[i]->setRange(0, vChunks[i]->size());
		m_threads_progress[i]->setValue(0);

		threads[i] = new QThread;
		worker[i] = new CCalcWorker(i, this, vChunks[i], chunkImage);

		worker[i]->moveToThread(threads[i]);
		threads[i]->start();
	
		m_threads_progress[i]->setRange(0, vChunks[i]->size());

		QMetaObject::invokeMethod(worker[i], "work", Qt::QueuedConnection);
		connect(worker[i], SIGNAL(valueChanged(int)),
				  m_threads_progress[i], SLOT(setValue(int)));
		connect(worker[i], SIGNAL(finished()), threads[i], SLOT(quit()), Qt::DirectConnection);
	}

	while(worker[0]->m_isWorking) {
		QCoreApplication::processEvents();
	}

	for(int i = 0; i < NUM_CHUNKS; ++i) {
		threads[i]->wait();
	}

	m_info_state_label->setText("step 5/5: sorting ...");

	m_shardList = new std::list<SShard>();
	for(int i = 0; i < NUM_CHUNKS; ++i) {
		for(int j = 0; j < vChunks[i]->size(); ++j) {
			m_shardList->push_back((*vChunks[i])[j]);
		}
	}

	m_shardList->sort(compare_area);

	m_list_shards->setRowCount(m_shardList->size());

	std::list<SShard>::iterator it;
	cnt = 0;
	for(it = m_shardList->begin(); it != m_shardList->end(); ++it) {
		SShard shard = *it;
		printf("%d:: %d qrtmm\n", cnt, (int)shard.A);
		
		m_list_shards->setItem(cnt, 0, new QTableWidgetItem(QString::number(cnt)));
		m_list_shards->setItem(cnt, 1, new QTableWidgetItem(QString::number(shard.x)));
		m_list_shards->setItem(cnt, 2, new QTableWidgetItem(QString::number(shard.y)));
		m_list_shards->setItem(cnt, 3, new QTableWidgetItem(QString::number((int)shard.A)));
		m_list_shards->setItem(cnt, 4, new QTableWidgetItem(QString::number(shard.U)));

		cnt++;
	}

	m_info_state_label->setText("Done");

	delete src;

	flag = true;
}

void CCalcShards::handle_color_shard(int y, int x)
{
	int X = -1;
	int Y = -1;

	if(QTableWidgetItem *item = m_list_shards->item(y, 1)) {
   	X = item->text().toInt();
  	}

	if(QTableWidgetItem *item = m_list_shards->item(y, 2)) {
   	Y = item->text().toInt();
  	}

	if(X == -1 || Y == -1)
		return;

	m_temp_color = m_shardQImage->pixel(X, Y); 

	CImage::flood4Fill(m_shardQImage, X, Y, QColor(m_temp_color), QColor(255, 0, 0));
	
	m_image_label->setPixmap(QPixmap::fromImage(*m_shardQImage).scaled(256, 256));
}

void CCalcShards::handle_clear_color()
{
	if(flag) {
		delete m_shardQImage;
		m_shardQImage = new QImage(*m_shardQImage_org);
		m_image_label->setPixmap(QPixmap::fromImage(*m_shardQImage_org).scaled(256, 256));
	}
}

void CCalcShards::handle_export()
{
	FILE* pFile = 0;
	if((pFile = fopen(QFileDialog::getSaveFileName(this, tr("Speichern"), "", tr("Tabelle (*.xml)")).toStdString().c_str(), "w")) == 0) {
		fclose(pFile);
		pFile = 0;
		return;
	}

	std::list<SShard>::iterator it;
	int cnt = 0;

	fprintf(pFile, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(pFile, "<shards>\n");

	for(it = m_shardList->begin(); it != m_shardList->end(); ++it) {
		SShard shard = *it;
		
		fprintf(pFile, "<shard id=\"%d\">\n", cnt);
			fprintf(pFile, "<id> %d </id>\n", cnt);
			fprintf(pFile, "<x> %d </x>\n", shard.x);
			fprintf(pFile, "<y> %d </y>\n", shard.y);
			fprintf(pFile, "<color> %d </color>\n", shard.iColor);
			fprintf(pFile, "<area> %.0f </area>\n", shard.A);
			fprintf(pFile, "<perimeter> %.2f </perimeter>\n", shard.U);
		fprintf(pFile, "</shard>\n");

		cnt++;
	}	

	fprintf(pFile, "</shards>\n");

	fclose(pFile);
	pFile = 0;
}

void CCalcShards::handle_save_image()
{
	if(flag) {
		m_shardQImage->save(QFileDialog::getSaveFileName(this, tr("Speichen"), "", 
													tr("Bilder (*.png *.bmp *.jpg)")));
	}
}

void CCalcShards::handle_draw_shard(int y, int x)
{
	if(flag) {
		int index = -1;
		if(QTableWidgetItem *item = m_list_shards->item(y, 0)) {
   		index = item->text().toInt();
  		}
	
		if(index != -1) {
			drawShard = new CDrawShard(m_shardList,
												index,
												m_shardQImage,
												m_shardQImage_org_org);
			drawShard->show();
		}
	}
}
