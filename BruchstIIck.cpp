#include <QtGui>

#include "BruchstIIck.h"

BruchstIIck::BruchstIIck()
{
	setMinimumSize(900, 562);
	setMaximumSize(900, 562);
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
					  QString("QProgressBar::chunk{width: 10px; background-color: #22AA33}")+
					  QString("QComboBox{background-color: #222222; color: #FFFFFF; border-radius: 2px;}") +
					  QString("QComboBox:focus{background-color: #444444; color: #FFFFFF; border-radius: 2px;}"));
					  //QString("QComboBox::drop-down:on{background-color: #222222; color: #FFFFFF;}"));

	m_imageOrg = new QLabel("", this);
	m_imageOrg->setGeometry(QRect(QPoint(10, 296), QSize(256, 256)));
	m_imageOrg->setMinimumSize(256, 256);
	m_imageOrg->setMaximumSize(256, 256);

	m_imageMod = new QLabel("", this);
	m_imageMod->setGeometry(QRect(QPoint(10, 30), QSize(256, 256)));
	m_imageMod->setMinimumSize(256, 256);
	m_imageMod->setMaximumSize(256, 256);

	QGroupBox* tools = new QGroupBox(tr("tools"), this);
	tools->setGeometry(QRect(QPoint(276, 30), QSize(250, 522)));
	
	QGroupBox* infos = new QGroupBox(tr("infos"), this);
	infos->setGeometry(QRect(QPoint(536, 30), QSize(284, 522)));

	QGroupBox* perimeter = new QGroupBox(tr("measure"), this);
	perimeter->setGeometry(QRect(QPoint(286, 392), QSize(230, 150)));

	m_histogram = new QLabel("", this);
	m_histogram->setGeometry(QRect(QPoint(546, 50), QSize(264, 90)));
	m_histogram->setMinimumSize(264, 90);
	m_histogram->setMaximumSize(264, 90);

	m_threshold_slider = new QSlider(Qt::Horizontal, this);
	m_threshold_slider->setGeometry(QRect(QPoint(549, 140), QSize(256, 20)));
	m_threshold_slider->setMinimumSize(256, 20);
	m_threshold_slider->setMaximumSize(256, 20);
	m_threshold_slider->setMinimum(0);
	m_threshold_slider->setSingleStep(1);
	m_threshold_slider->setPageStep(10);
	m_threshold_slider->setMaximum(255);
	m_threshold_slider->setSliderPosition(120);
	connect(m_threshold_slider, SIGNAL(valueChanged(int)), this, SLOT(handle_threshold_slider()));	

	m_slider_pos = new QLabel("120", this);
	m_slider_pos->setGeometry(QRect(QPoint(780, 170), QSize(30, 20)));
	m_slider_pos->setStyleSheet("background-color: #DDDDDD; border-radius: 2px; border: 1px solid #000000; color: #000000;");
	m_slider_pos->setMinimumSize(30, 20);
	m_slider_pos->setMaximumSize(30, 20);

	QLabel* tempLabel = new QLabel("Threshold:", this);
	tempLabel->setGeometry(QRect(QPoint(700, 170), QSize(80, 20)));
	tempLabel->setStyleSheet("border-style: none; color: #000000; background-color: #FFFFFF;");
	tempLabel->setMinimumSize(80, 20);
	tempLabel->setMaximumSize(80, 20);

	m_image_infos = new QLabel("Size: 0 x 0", this);
	m_image_infos->setGeometry(QRect(QPoint(546, 200), QSize(264, 20)));
	m_image_infos->setMinimumSize(264, 20);
	m_image_infos->setMaximumSize(264, 20);

	m_mean_button = new QPushButton("mean", this);
	m_mean_button->setGeometry(QRect(QPoint(446, 140), QSize(70, 20)));
	connect(m_mean_button, SIGNAL(released()), this, SLOT(handle_mean_filter()));

	m_mean_edit = new QLineEdit("1", this);
	m_mean_edit->setGeometry(QRect(QPoint(411, 140), QSize(30, 20)));

	m_median_button = new QPushButton("median", this);
	m_median_button->setGeometry(QRect(QPoint(321, 140), QSize(70, 20)));
	connect(m_median_button, SIGNAL(released()), this, SLOT(handle_median_filer()));
	
	m_median_edit = new QLineEdit("1", this);
	m_median_edit->setGeometry(QRect(QPoint(286, 140), QSize(30, 20)));

	m_laplacianW_edit = new QLineEdit("1", this);
	m_laplacianW_edit->setGeometry(QRect(QPoint(286, 170), QSize(30, 20)));

	m_laplacianW_button = new QPushButton(tr("laplacian"), this);
	m_laplacianW_button->setGeometry(QRect(QPoint(321, 170), QSize(70, 20)));
	connect(m_laplacianW_button, SIGNAL(released()), this, SLOT(handle_laplacianW_filter()));
/*
	m_laplacian_button = new QPushButton(tr("laplacian"), this);
	m_laplacian_button->setGeometry(QRect(QPoint(406, 170), QSize(110, 20)));
	connect(m_laplacian_button, SIGNAL(released()), this, SLOT(handle_laplacian_filter()));

	m_sobel_button = new QPushButton(tr("sobel"), this);
	m_sobel_button->setGeometry(QRect(QPoint(286, 200), QSize(70, 20)));
	connect(m_sobel_button, SIGNAL(released()), this, SLOT(handle_sobel_filter()));

	m_scharr_button = new QPushButton(tr("scharr"), this);
	m_scharr_button->setGeometry(QRect(QPoint(366, 200), QSize(70, 20)));
	connect(m_scharr_button, SIGNAL(released()), this, SLOT(handle_scharr_filter()));

	m_roberts_button = new QPushButton(tr("roberts"), this);
	m_roberts_button->setGeometry(QRect(QPoint(446, 200), QSize(70, 20)));
	connect(m_roberts_button, SIGNAL(released()), this, SLOT(handle_roberts_filter()));

	m_kirsch_button = new QPushButton(tr("kirsch"), this);
	m_kirsch_button->setGeometry(QRect(QPoint(286, 230), QSize(70, 20)));
	connect(m_kirsch_button, SIGNAL(released()), this, SLOT(handle_kirsch_filter()));
*/
	m_edge_detector_combo = new QComboBox(this);
	m_edge_detector_combo->setGeometry(QRect(QPoint(286, 200), QSize(105, 20)));
	QListView * listView = new QListView(m_edge_detector_combo);
	listView->setStyleSheet("QListView::item {background-color: #222222; color: #FFFFFF; border-style: none;} QListView{border-style: none;}");
	m_edge_detector_combo->addItem("laplacian");
	m_edge_detector_combo->addItem("sobel");
	m_edge_detector_combo->addItem("scharr");
	m_edge_detector_combo->addItem("roberts");
	m_edge_detector_combo->addItem("kirsch");
	m_edge_detector_combo->setView(listView);
	connect(m_edge_detector_combo, SIGNAL(activated(int)), this, SLOT(handle_edge_detecter_combo(int)));

	m_light_add_button = new QPushButton(tr("+"), this);
	m_light_add_button->setGeometry(QRect(QPoint(286, 50), QSize(20, 20)));
	connect(m_light_add_button, SIGNAL(released()), this, SLOT(handle_light_add()));

	m_light_sub_button = new QPushButton(tr("-"), this);
	m_light_sub_button->setGeometry(QRect(QPoint(316, 50), QSize(20, 20)));
	connect(m_light_sub_button, SIGNAL(released()), this, SLOT(handle_light_sub()));

	m_global_contrast_button = new QPushButton(tr("contrast"), this);
	m_global_contrast_button->setGeometry(QRect(QPoint(356, 80), QSize(70, 20)));
	connect(m_global_contrast_button, SIGNAL(released()), this, SLOT(handle_global_contrast()));

	m_g_contrast_min_edit = new QLineEdit(tr("0"), this);
	m_g_contrast_min_edit->setGeometry(QRect(QPoint(286, 80), QSize(30, 20)));

	m_g_contrast_max_edit = new QLineEdit(tr("255"), this);
	m_g_contrast_max_edit->setGeometry(QRect(QPoint(321, 80), QSize(30, 20)));

	m_gamma_patch_button = new QPushButton(tr("gamma"), this);
	m_gamma_patch_button->setGeometry(QRect(QPoint(356, 110), QSize(70, 20)));
	connect(m_gamma_patch_button, SIGNAL(released()), this, SLOT(handle_gamma_patch()));

	m_gamma_patch_max_edit = new QLineEdit(tr("255"), this);
	m_gamma_patch_max_edit->setGeometry(QRect(QPoint(286, 110), QSize(30, 20)));
	
	m_gamma_patch_gamma_edit = new QLineEdit(tr("1"), this);
	m_gamma_patch_gamma_edit->setGeometry(QRect(QPoint(321, 110), QSize(30, 20)));

	m_invert_button = new QPushButton(tr("invert"), this);
	m_invert_button->setGeometry(QRect(QPoint(346, 50), QSize(70, 20)));
	connect(m_invert_button, SIGNAL(released()), this, SLOT(handle_invert_filter()));

	m_set_threshold_button = new QPushButton(tr("set"), this);
	m_set_threshold_button->setGeometry(QRect(QPoint(546, 170), QSize(70, 20)));
	connect(m_set_threshold_button, SIGNAL(released()), this, SLOT(handle_global_threshold_filter()));

	QLabel* border_info_label = new QLabel(tr("bordersize:"), this);
	border_info_label->setGeometry(QRect(QPoint(296, 412), QSize(70, 20)));
	border_info_label->setStyleSheet("border-style: none; color: #000000; background-color: #FFFFFF;");

	m_border_width_edit = new QLineEdit(tr("2"), this);
	m_border_width_edit->setGeometry(QRect(QPoint(376, 412), QSize(30, 20)));

	m_set_border_button = new QPushButton(tr("set border"), this);
	m_set_border_button->setGeometry(QRect(QPoint(416, 412), QSize(70, 20)));
	connect(m_set_border_button, SIGNAL(released()), this, SLOT(handle_set_border_filter()));

	m_calcShards_button = new QPushButton(tr("calc shards"), this);
	m_calcShards_button->setGeometry(QRect(QPoint(296, 510), QSize(210, 20)));
	m_calcShards_button->setStyleSheet("background-color: #225522;");
	connect(m_calcShards_button, SIGNAL(released()), this, SLOT(handle_calcShards()));

	m_custom_edit = new QLineEdit(tr("# custom command"), this);
	m_custom_edit->setGeometry(QRect(QPoint(286, 362), QSize(170, 20)));

	m_custom_button = new QPushButton(tr("add"), this);
	m_custom_button->setGeometry(QRect(QPoint(466, 362), QSize(50, 20)));
	m_custom_button->setStyleSheet("background-color: #225522;");
	connect(m_custom_button, SIGNAL(released()), this, SLOT(handle_custom_filter()));

	m_undo_button = new QPushButton("undo", this);
	m_undo_button->setGeometry(QRect(QPoint(446, 50), QSize(70, 20)));
	m_undo_button->setStyleSheet("background-color: #222255;");
	connect(m_undo_button, SIGNAL(released()), this, SLOT(handle_undo_button()));

	m_load_program_button = new QPushButton("load", this);
	m_load_program_button->setGeometry(QRect(QPoint(546, 382), QSize(50, 20)));
	connect(m_load_program_button, SIGNAL(released()), this, SLOT(handle_load_program()));

	m_save_program_button = new QPushButton("save", this);
	m_save_program_button->setGeometry(QRect(QPoint(606, 382), QSize(50, 20)));
	connect(m_save_program_button, SIGNAL(released()), this, SLOT(handle_save_program()));

	m_clear_program_button = new QPushButton("clear", this);
	m_clear_program_button->setGeometry(QRect(QPoint(680, 382), QSize(50, 20)));
	m_clear_program_button->setStyleSheet("background-color: #552222;");
	connect(m_clear_program_button, SIGNAL(released()), this, SLOT(handle_clear_program()));

	m_run_program_button = new QPushButton("run", this);
	m_run_program_button->setGeometry(QRect(QPoint(740, 382), QSize(70, 20)));
	m_run_program_button->setStyleSheet("background-color: #222255;");
	connect(m_run_program_button, SIGNAL(released()), this, SLOT(handle_run_program()));

	m_program_edit = new QTextEdit("", this);
	m_program_edit->setGeometry(QRect(QPoint(546, 412), QSize(264, 100)));

	m_prog_progress = new QProgressBar(this);
	m_prog_progress->setGeometry(QRect(QPoint(546, 522), QSize(264, 20)));
	m_prog_progress->setRange(0, 100);
	m_prog_progress->setValue(0);

	createActions();
	createMenus();

	setWindowTitle(tr("Bruchbild-Auswertung"));
	resize(500, 400);
}

void BruchstIIck::createMenus()
{
	m_file_Menu = new QMenu(tr("File"), this);
	m_file_Menu->addAction(m_load_action);
	m_file_Menu->addAction(m_save_action);
	m_file_Menu->addSeparator();
	m_file_Menu->addAction(m_close_action);

	m_program_Menu = new QMenu(tr("Program"), this);
	m_program_Menu->addAction(m_load_prog_action);
	m_program_Menu->addAction(m_save_prog_action);
	m_program_Menu->addSeparator();
	m_program_Menu->addAction(m_clear_prog_action);
	m_program_Menu->addAction(m_pop_program_action);
	m_program_Menu->addAction(m_run_prog_action);

	m_help_Menu = new QMenu(tr("Help"), this);
	m_help_Menu->addAction(m_message_about_action);

	menuBar()->addMenu(m_file_Menu);
	menuBar()->addMenu(m_program_Menu);
	menuBar()->addMenu(m_help_Menu);
}

void BruchstIIck::createActions()
{
	m_load_action = new QAction(tr("&Load..."), this);
	connect(m_load_action, SIGNAL(triggered()), this, SLOT(load()));

	m_save_action = new QAction(tr("&Save..."), this);
	connect(m_save_action, SIGNAL(triggered()), this, SLOT(save()));

	m_close_action = new QAction(tr("&Close..."), this);
	connect(m_close_action, SIGNAL(triggered()), this, SLOT(close()));

	m_load_prog_action = new QAction(tr("Load..."), this);
	connect(m_load_prog_action, SIGNAL(triggered()), this, SLOT(handle_load_program()));	

	m_save_prog_action = new QAction(tr("Save..."), this);
	connect(m_save_prog_action, SIGNAL(triggered()), this, SLOT(handle_save_program()));	

	m_clear_prog_action = new QAction(tr("Clear..."), this);
	connect(m_clear_prog_action, SIGNAL(triggered()), this, SLOT(handle_clear_program()));

	m_run_prog_action = new QAction(tr("Run..."), this);
	connect(m_run_prog_action, SIGNAL(triggered()), this, SLOT(handle_run_program()));

	m_pop_program_action = new QAction(tr("pop command"), this);
	connect(m_pop_program_action, SIGNAL(triggered()), this, SLOT(handle_pop_program()));

	m_message_about_action = new QAction(tr("about the Program"), this);
	connect(m_message_about_action, SIGNAL(triggered()), this, SLOT(handle_message_about()));
}

void BruchstIIck::load()
{
	images.clear();
	QImage image = QImage(QFileDialog::getOpenFileName(this, tr("Öffnen"), "", tr("Bilder (*.png *.bmp *.jpg)")));
	images.push_back(image);
	m_imageOrg->setPixmap(QPixmap::fromImage(image).scaled(256, 256));
	m_imageMod->setPixmap(QPixmap::fromImage(image).scaled(256, 256));
	createHistogram();

	m_image_org_org = image;

	m_image_infos->setText("Size: "+ QString::number(image.width()) + " x " + QString::number(image.height()));
}

void BruchstIIck::save()
{
	if(images.size() > 0) {
		images[images.size()-1].save(QFileDialog::getSaveFileName(this, tr("Speichen"), "", 
													tr("Bilder (*.png *.bmp *.jpg)")));	
	}
}

void BruchstIIck::handle_mean_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.mean(m_mean_edit->text().toInt());
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("mean " + m_mean_edit->text().toStdString());
	}
}

void BruchstIIck::handle_median_filer()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.median(m_median_edit->text().toInt());
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("median " + m_median_edit->text().toStdString());
	}
}

void BruchstIIck::handle_laplacian_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.laplacian();
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("laplacian");
	}
}

void BruchstIIck::handle_laplacianW_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.laplacian(m_laplacianW_edit->text().toInt());
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("laplacianW " + m_laplacianW_edit->text().toStdString());
	}
}

void BruchstIIck::handle_sobel_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.sobel();
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("sobel");
	}
}

void BruchstIIck::handle_scharr_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.scharr();
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("scharr");
	}
}

void BruchstIIck::handle_kirsch_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.kirsch();
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("kirsch");
	}
}

void BruchstIIck::handle_roberts_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.roberts();
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("roberts");
	}
}

void BruchstIIck::handle_light_add()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.addLight(1.2f);
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("addLight 1.2");
	}
}

void BruchstIIck::handle_light_sub()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.addLight(0.9);
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("addLight 0.9");
	}
}

void BruchstIIck::handle_invert_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.invert();
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("invert");
	}
}

void BruchstIIck::handle_global_threshold_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.globalThreshold(m_slider_pos->text().toInt());
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("globalThreshold " + m_slider_pos->text().toStdString());
	}
}

void BruchstIIck::handle_global_contrast()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.globalContrast(m_g_contrast_min_edit->text().toInt(),
								 m_g_contrast_max_edit->text().toInt());
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("globalContrast " + m_g_contrast_min_edit->text().toStdString() +
						 " " + m_g_contrast_max_edit->text().toStdString());
	}
}

void BruchstIIck::handle_gamma_patch()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.gammaPatch(m_gamma_patch_max_edit->text().toInt(),
							m_gamma_patch_gamma_edit->text().toInt());
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("gammaPatch " + m_gamma_patch_max_edit->text().toStdString() +
						 " " + m_gamma_patch_gamma_edit->text().toStdString());
	}
}

void BruchstIIck::handle_edge_detecter_combo(int i)
{
	switch(i) {
		case 0: handle_laplacian_filter(); break;
		case 1: handle_sobel_filter(); 	  break;
		case 2: handle_scharr_filter();	  break;
		case 3: handle_roberts_filter();	  break;
		case 4: handle_kirsch_filter();	  break;
	}
}

void BruchstIIck::handle_set_border_filter()
{
	if(images.size() > 0) {
		CImage img(&images[images.size()-1]);
		img.setBorder(m_border_width_edit->text().toInt());
		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
		addToProgram("setBorder " + m_border_width_edit->text().toStdString());
	}
}

void BruchstIIck::handle_custom_filter()
{
	addToProgram(m_custom_edit->text().toStdString());
}

void BruchstIIck::handle_undo_button()
{
	if(images.size() > 1) {
		images.pop_back();

		if(m_program.size() > 0)
			m_program.pop_back();
		
		std::string text;
		for(int i = 0; i < m_program.size(); ++i) {
			if(i < m_program.size()-1)
				text.append(m_program[i] + "\n");
			else
				text.append(m_program[i]);
		}
		m_program_edit->setText(QString(text.c_str()));
		m_program_edit->verticalScrollBar()->setSliderPosition(m_program_edit->verticalScrollBar()->maximum());
		
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
	}
}

void BruchstIIck::createHistogram()
{
	QImage image(264, 90, QImage::Format_RGB32);
	image.fill(QColor(255, 255, 255));	

	CImage img(&images[images.size()-1]);
	img.calcHistogram();

	int iHistBlock = 0;

	float numPixel = (float)(img.width*img.height);
	float temp = 0;
	for(int i = 0; i < 256; ++i) {
		if(img.histogram[i] > 0) iHistBlock++;
		temp = (float) img.histogram[i];
		temp /= numPixel;
		img.histogram[i] = 80-(int)(temp*60.0f*(float)iHistBlock);

		if(img.histogram[i] < 0) img.histogram[i] = 0;
	}

	int color = 0;
	for(int i = 3; i < 259; i++) {
		 color = i-3;
	    for(int j = 80; j >= img.histogram[i-3]; j--)
			image.setPixel(i, j,  QColor(color, color, color).rgb());
	}

	for(int i = 3; i < 259; ++i)
		image.setPixel(i, 80,  QColor(0, 0, 0).rgb());

	for(int i = 80; i > 20; --i) {
		image.setPixel(2, i,  QColor(0, 0, 0).rgb());
		image.setPixel(259, i,  QColor(0, 0, 0).rgb());
	}

	m_histogram->setPixmap(QPixmap::fromImage(image));
}

void BruchstIIck::handle_threshold_slider()
{
	m_slider_pos->setText(QString::number(m_threshold_slider->value()));
}

void BruchstIIck::handle_load_program()
{
	m_program.clear();
	m_prog_progress->setRange(0, 100);
	m_prog_progress->setValue(0);
	std::ifstream file;
	file.open(QFileDialog::getOpenFileName(this, tr("Öffnen"), "", tr("Program (*.prg)")).toStdString().c_str());
	if(!file.good()) {
		return;
	}

	std::string line;
	while(getline(file, line, '\n')) {
		m_program.push_back(line);
	}

	file.close();

	std::string text;
	for(int i = 0; i < m_program.size(); ++i) {
		if(i < m_program.size()-1)
			text.append(m_program[i] + "\n");
		else
			text.append(m_program[i]);
	}
	m_program_edit->setText(QString(text.c_str()));
	m_program_edit->verticalScrollBar()->setSliderPosition(m_program_edit->verticalScrollBar()->maximum());
}

void BruchstIIck::handle_save_program()
{
	FILE* pFile = 0;
	if((pFile = fopen(QFileDialog::getSaveFileName(this, tr("Speichen"), "", 
							tr("Program (*.prg)")).toStdString().c_str(), "w")) == 0)
	{
		fclose(pFile);
		pFile = 0;
		return;
	}
		
	for(int i = 0; i < m_program.size(); ++i) {
		if(i < m_program.size()-1)
			fprintf(pFile, "%s\n", m_program[i].c_str());
		else
			fprintf(pFile, "%s", m_program[i].c_str());
	}

	fclose(pFile);
	pFile = 0;
	return;
}

void BruchstIIck::handle_run_program()
{
	if(images.size() > 0) {
		std::string filter;
		m_prog_progress->setRange(0, m_program.size());
		m_prog_progress->setValue(0);

		CImage img(&images[images.size()-1]);

		for(int i = 0; i < m_program.size(); ++i) {
			std::stringstream line(m_program[i]);
			line >> filter;

			if(filter == "mean") {
				int param;
				line >> param;
				img.mean(param);
			}
			else if(filter == "median") {
				int param;
				line >> param;
				img.median(param);
			}
			else if(filter == "laplacian") {
				img.laplacian();
			}
			else if(filter == "addLight") {
				float param;
				line >> param;
				img.addLight(param);
			}
			else if(filter == "invert") {
				img.invert();
			}
			else if(filter == "setBorder") {
				int param;
				line >> param;
				img.setBorder(param);
			}
			else if(filter == "laplacianW") {
				int param;
				line >> param;
				img.laplacian(param);
			}
			else if(filter == "sobel") {
				img.sobel();
			}
			else if(filter == "scharr") {
				img.scharr();
			}
			else if(filter == "kirsch") {
				img.kirsch();
			}
			else if(filter == "roberts") {
				img.roberts();
			}
			else if(filter == "globalThreshold") {
				int param;
				line >> param;
				img.globalThreshold(param);
			}
			else if(filter == "globalContrast") {
				int min;
				int max;
				line >> min >> max;
				img.globalContrast(min, max);
			}
			else if(filter == "gammaPatch") {
				int max;
				int gamma;
				line >> max >> gamma;
				img.gammaPatch(max, gamma);
			}
			else if(filter == "seedRegionGrowing") {
				int x;
				int y;
				int t;
				int c;
				line >> x >> y >> t >> c;
				img.seedRegionGrowing(x, y, t, c);
			}
			else if(filter == "regionGrowing") {
				int l;
				int t;
				int c;
				line >> l >> t >> c;
				img.regionGrowing(l, t, c);
			}
	
			m_prog_progress->setValue(i+1);
		}

		images.push_back(img.get());
		m_imageMod->setPixmap(QPixmap::fromImage(images[images.size()-1]).scaled(256, 256));
		createHistogram();
	}
}

void BruchstIIck::handle_pop_program()
{
	std::string text;
	if(m_program.size() > 0) {
		m_program.pop_back();

		for(int i = 0; i < m_program.size(); ++i) {
			if(i < m_program.size()-1)
				text.append(m_program[i] + "\n");
			else
				text.append(m_program[i]);
		}
		m_program_edit->setText(QString(text.c_str()));
		m_program_edit->verticalScrollBar()->setSliderPosition(m_program_edit->verticalScrollBar()->maximum());
	}
}

void BruchstIIck::handle_clear_program()
{
	m_program.clear();
	m_prog_progress->setRange(0, 100);
	m_prog_progress->setValue(0);
	m_program_edit->setText("");
	m_program_edit->verticalScrollBar()->setSliderPosition(m_program_edit->verticalScrollBar()->maximum());
}

void BruchstIIck::addToProgram(std::string param)
{
	std::string text;
	m_program.push_back(param);

	for(int i = 0; i < m_program.size(); ++i) {
		if(i < m_program.size()-1)
			text.append(m_program[i] + "\n");
		else
			text.append(m_program[i]);
	}
	m_program_edit->setText(QString(text.c_str()));
	m_program_edit->verticalScrollBar()->setSliderPosition(m_program_edit->verticalScrollBar()->maximum());
}

void BruchstIIck::handle_message_about()
{
	QMessageBox::information(this, tr("About BruchstIIck"),
             tr("<p>Das Bildbearbeitungstool <b>BruchstIIck</b> besteht"
					 "aus einer Reihe von implementierten Filtermechanismen, "
					 "die zur Auswertung und Segmentierung von Regionen in Bildern dienen.</p>"
					 "Im folgenden werden vorhandene Aktionen beschrieben:"
					 "<div><tabel>"
								"<tr><td><b>+</b></td><td>verstärkt die Helligkeit</td></tr>"
								"<tr><td><b>-</b></td><td>senkt die Helligkeit</td></tr>"
								"<tr><td><b>invert</b></td><td>invertiert die Farben</td></tr>"
								"<tr><td><b>undo</b></td><td>wiederuft die letzte Bearbeitung</td></tr>"
								"<tr><td><b>invert</b></td><td></td></tr>"
								"<tr><td><b>invert</b></td><td></td></tr>"
								"<tr><td><b>invert</b></td><td></td></tr>"
					 "</tabel></div>"));
}

void BruchstIIck::handle_calcShards()
{
	if(images.size() > 0) {
		ccalcShards = new CCalcShards(images[images.size()-1], m_image_org_org);
		ccalcShards->show();
	}
}
