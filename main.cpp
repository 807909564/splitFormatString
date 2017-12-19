#include <QCoreApplication>
#include <QDebug>

/*
 * source 要修改的字符串
 * nSpacing 指定间距,默认为1
 * ch 要插入的字符串,默认为 空格
 */

QString splitFormatString(const QString source,
                          int nSpacing = 1,
                          const QString &ch = QString(" ")) {
    QString result = source;
    if (source.size() <= nSpacing) {
        result.push_front(ch);
    } else {
        result.clear();
        for (int i = 0; i < source.size();) {
            result.append(source.mid(i,nSpacing));
            i += nSpacing;
            if (i < source.size()) {
                result.append(ch);
            }
        }
    }
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString testString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    qDebug() << "source string:" << testString;
    QString resultString = splitFormatString(testString,3);
    qDebug() << "resultString string:" << resultString;
    QString resultOthString = splitFormatString(testString,27);
    qDebug() << "resultOthString string:" << resultOthString;
    return a.exec();
}
