/***************************************************************************
 *   Copyright (C) 2007 by dogangolcuk   *
 *   dogangolcuk@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <QCoreApplication>
#include "anaPencere.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    	QApplication app(argc,argv);
  	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	#ifdef Q_WS_X11
        db.setDatabaseName("/usr/share/sozluk/sozlukdb");
	#else ifdef Q_WS_WIN
	db.setDatabaseName("C:\sozlukdb");
	#endif
	      if(db.open())
        		 qDebug("Veritabanı bağlandı");
      	      else 
	 		 QMessageBox::information(0, QString::fromUtf8("Sözlük"),
                         QString::fromUtf8("Veritabanı Bağlanılamadı."),
                         QMessageBox::Close);
    anaPencere *form = new anaPencere;
    form->show();
    return app.exec();
}

