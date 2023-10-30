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
#include "anaPencere.h"
#include <QMessageBox>
#include <QHeaderView>
 #include <QSyntaxHighlighter>
 #include "higlighter.h"
anaPencere::anaPencere()
{
        setupUi(this);
     
	rBEng2Tr->setChecked(true);
	model = new QSqlQueryModel;
	if(rBEng2Tr->isChecked()){
     		model->setQuery("SELECT sozluk_en2tr_kelime, sozluk_en2tr_anlam FROM sozluk_en2tr");
	}
	if(rBTur2Eng->isChecked()){
     		model->setQuery("SELECT sozluk_tr2en_kelime, sozluk_tr2en_anlam FROM sozluk_tr2en");
	}

	if(rBimla->isChecked()){
		mapper->addMapping(anlam, 0);
		model->setQuery("SELECT imla_kelime FROM imla");
	}
     	tablo->setModel(model);
     	tablo->setColumnHidden(1,true);
     	model->setHeaderData(0, Qt::Horizontal, tr("Kelime"));    
	tablo->verticalHeader()->hide();
	tablo->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
     	tablo->show();
 //burası neden çalışmıyor.
	tablo->horizontalHeader()->setClickable(true);
	tablo->setSortingEnabled(true);
// QObject::connect(tablo->horizontalHeader(),SIGNAL(sectionClicked(int)),tablo,SLOT(sortByColumn(int)));

  mapper = new QDataWidgetMapper;
  mapper->setModel(model);
  mapper->addMapping(anlam, 1);

connect(arama_kutusu,SIGNAL(textChanged ( const QString &  )),this,SLOT(Ara(const QString &)));
// connect(textara,SIGNAL(textChanged ( const QString &  )),this,SLOT(texAra(const QString &)));
connect(tablo,SIGNAL(activated ( const QModelIndex & )),this,SLOT(tablodolas(const QModelIndex &)));
connect(tablo,SIGNAL(pressed ( const QModelIndex & )),this,SLOT(tablodolas(const QModelIndex &)));
connect(tb,SIGNAL(clicked ()),this,SLOT(hakkinda()));
}
void anaPencere::Ara(const QString & text )
{
model->clear();
model->setHeaderData(0, Qt::Horizontal, tr("Kelime")); 

QString ara;
if(rBEng2Tr->isChecked()){
mapper->addMapping(anlam, 1);
ara.append( "lower(sozluk_en2tr_kelime) LIKE '");
ara.append(text.toLower());
ara.append("%'");
model->setQuery("SELECT sozluk_en2tr_kelime, sozluk_en2tr_anlam FROM sozluk_en2tr WHERE "+ara+"LIMIT 100");
if(!model->canFetchMore(model->index(0, 1)))
texAra(text);
model->query();
mapper->setCurrentModelIndex(model->index(0, 1));
}else
if(rBTur2Eng->isChecked()){
mapper->addMapping(anlam, 1);
ara.append( "lower(sozluk_tr2en_kelime) LIKE '");
ara.append(text.toLower());
ara.append("%'");
model->setQuery("SELECT sozluk_tr2en_kelime, sozluk_tr2en_anlam FROM sozluk_tr2en WHERE "+ara+"LIMIT 100");
if(!model->canFetchMore(model->index(0, 1)))
texAra(text);
model->query();
mapper->setCurrentModelIndex(model->index(0, 1));
}else
if(rBimla->isChecked()){
mapper->addMapping(anlam, 0);
ara.append( "lower(imla_kelime) LIKE '");
ara.append(text.toLower());
ara.append("%'");
model->setQuery("SELECT imla_kelime FROM imla WHERE "+ara+"LIMIT 100");
model->query();
mapper->setCurrentModelIndex(model->index(0, 0));
}

// model->query();
// mapper->setCurrentModelIndex(model->index(0, 1));
tablo->setColumnHidden(1,true);

}
void anaPencere::texAra(const QString & text )
{
//  QTextEdit *editor = new QTextEdit;
//  Highlighter *aydinlat = new Highlighter(anlam->document());
// aydinlat->ayd(text);
// QTextDocument *gercek= anlam->document();
// anlam->document()->redo();
     QTextCharFormat myClassFormat;
     myClassFormat.setFontWeight(QFont::Bold);
     myClassFormat.setForeground(Qt::red);
     anlam->document()->find(text).setCharFormat(myClassFormat);

}
void anaPencere::tablodolas(const QModelIndex & index)
{

mapper->setCurrentModelIndex(index);

}


void anaPencere::hakkinda()
{
 QMessageBox::information(this, QString::fromUtf8("Basit Sözlük"),
                          QString::fromUtf8("<center>Basit Sözlük<br>2007-2011<br>dogangolcuk@gmail.com</center>"),
                          QMessageBox::Close);
}
