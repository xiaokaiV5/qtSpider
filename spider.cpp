#include <QString>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QRegExp>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
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
	QRegularExpression re("<div class=\"2u(.*?)target");
	//QRegularExpression re("href=(.*?)target");
	QRegularExpressionMatch match;
	//QRegExp re_beg("icon1");           //��ʼƥ���־
	//QRegExp re_end(tr("�ƶ���"));            //����ƥ���־

	//int index_beg = tmdStr.indexOf(re_beg, 0);         //��ʼƥ��λ��
	//int index_end = tmdStr.indexOf(re_end, index_beg);     //����ƥ��λ��
	int i = 1;
	int index_beg;
	match = re.match(tmdStr,0);
	QStringList tvUrlList;
	while (match.hasMatch())
	{
		tvUrlList.append(match.captured(0));

		index_beg = tmdStr.indexOf(match.captured(0))+1;
		match = re.match(tmdStr, index_beg);

		qDebug() << match.captured(0) << endl;
	}
		

	return 0;
}