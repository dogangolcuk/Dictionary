 /****************************************************************************
 **
 ** Copyright (C) 2005-2007 Trolltech ASA. All rights reserved.
 **
 ** This file is part of the example classes of the Qt Toolkit.
 **
 ** This file may be used under the terms of the GNU General Public
 ** License version 2.0 as published by the Free Software Foundation
 ** and appearing in the file LICENSE.GPL included in the packaging of
 ** this file.  Please review the following information to ensure GNU
 ** General Public Licensing requirements will be met:
 ** http://trolltech.com/products/qt/licenses/licensing/opensource/
 **
 ** If you are unsure which license is appropriate for your use, please
 ** review the following information:
 ** http://trolltech.com/products/qt/licenses/licensing/licensingoverview
 ** or contact the sales department at sales@trolltech.com.
 **
 ** In addition, as a special exception, Trolltech gives you certain
 ** additional rights. These rights are described in the Trolltech GPL
 ** Exception version 1.0, which can be found at
 ** http://www.trolltech.com/products/qt/gplexception/ and in the file
 ** GPL_EXCEPTION.txt in this package.
 **
 ** In addition, as a special exception, Trolltech, as the sole copyright
 ** holder for Qt Designer, grants users of the Qt/Eclipse Integration
 ** plug-in the right for the Qt/Eclipse Integration to link to
 ** functionality provided by Qt Designer and its related libraries.
 **
 ** Trolltech reserves all rights not expressly granted herein.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ****************************************************************************/

 #include <QtGui>

 #include "higlighter.h"

 Highlighter::Highlighter(QTextDocument *parent)
     : QSyntaxHighlighter(parent)
 {
     HighlightingRule rule;

     keywordFormat.setForeground(Qt::darkBlue);
     keywordFormat.setFontWeight(QFont::Bold);
     QStringList keywordPatterns;
     keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                     << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                     << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                     << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                     << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                     << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                     << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                     << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                     << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                     << "\\bvoid\\b" << "\\bvolatile\\b";
     foreach (QString pattern, keywordPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = keywordFormat;
         highlightingRules.append(rule);
     }

// //      classFormat.setFontWeight(QFont::Bold);
// //      classFormat.setForeground(Qt::darkMagenta);
//      rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
//      rule.format = classFormat;
//      highlightingRules.append(rule);
// 
//      singleLineCommentFormat.setForeground(Qt::red);
//      rule.pattern = QRegExp("//[^\n]*");
//      rule.format = singleLineCommentFormat;
//      highlightingRules.append(rule);
// 
//      multiLineCommentFormat.setForeground(Qt::red);
// 
//      quotationFormat.setForeground(Qt::darkGreen);
//      rule.pattern = QRegExp("\".*\"");
//      rule.format = quotationFormat;
//      highlightingRules.append(rule);

//      functionFormat.setFontItalic(true);
//      functionFormat.setForeground(Qt::blue);
//      rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
//      rule.format = functionFormat;
//      highlightingRules.append(rule);

//      commentStartExpression = QRegExp("/\\*");
//      commentEndExpression = QRegExp("\\*/");
 }

 void Highlighter::highlightBlock(const QString &text)
 {
      QTextCharFormat myClassFormat;
     myClassFormat.setFontWeight(QFont::Bold);
     myClassFormat.setForeground(Qt::darkMagenta);
     QString pattern = "\\b"+text+"\\b";
qDebug()<<pattern;
     QRegExp expression(pattern);
     int index = text.indexOf(expression);
     while (index >= 0) {
         int length = expression.matchedLength();
         setFormat(index, length, myClassFormat);
         index = text.indexOf(expression, index + length);
      }
 }
 void Highlighter::ayd(const QString &text)
 {
      QTextCharFormat myClassFormat;
     myClassFormat.setFontWeight(QFont::Bold);
     myClassFormat.setForeground(Qt::darkMagenta);
     QString pattern = "\\b"+text+"\\b";
qDebug()<<pattern;
     QRegExp expression(pattern);
     int index = text.indexOf(expression);
     while (index >= 0) {
         int length = expression.matchedLength();
         setFormat(index, length, myClassFormat);
         index = text.indexOf(expression, index + length);
      }
 }