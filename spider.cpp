#include <QString>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include "spider.h"


Spider::Spider(const QString urlStr)
{
	mananger = new QNetworkAccessManager(this);
	url = new QUrl(urlStr);
	connect(mananger, &QNetworkAccessManager::finished, this, &Spider::replay_finished);
}

Spider::~Spider()
{
}

int Spider::spiderStart()
{
	mananger->get(QNetworkRequest(*url));
	
	return 0;
}


int Spider::replay_finished(QNetworkReply *reply)
{
	web_data = reply->readAll();
	QString tmdStr = web_data;
	qDebug() << tmdStr << endl;
	return 0;
}