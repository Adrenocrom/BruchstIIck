TARGET  = BruchstIIck

HEADERS = BruchstIIck.h \
			 image.h \
			 calcShards.h \
			 calcWorker.h \
			 drawShard.h
SOURCES = BruchstIIck.cpp \
			 main.cpp \
			 image.cpp \
			 calcShards.cpp \
			 calcWorker.cpp \
			 drawShard.cpp

wince*: {
   DEPLOYMENT_PLUGIN += qjpeg qgif
}
