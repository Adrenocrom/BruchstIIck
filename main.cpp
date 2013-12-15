#include <QApplication>
#include <QTextStream>

#include "BruchstIIck.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	BruchstIIck bruchstIIck;
	bruchstIIck.show();
	return app.exec();
}
