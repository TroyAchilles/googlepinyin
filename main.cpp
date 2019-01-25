#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
#include "pinyinime.h"
using namespace ime_pinyin;
struct MaxLimt
{
    constexpr static size_t spelling_len = 32;
    constexpr static size_t decoded_len = 32;
    constexpr static size_t zh_len = 20;
    constexpr static size_t change_times = 0;
};

struct DefInfo
{
    constexpr static char* sys_dict = (char*)"dict/dict_pinyin.dat";
    constexpr static char* user_dict = (char*)"dict/dict_pinyin_user.dat";
};


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QTextCodec* code = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(code);
    QTextCodec::setCodecForCStrings(code);
    QTextCodec::setCodecForTr(code);

    QString dir(qApp->applicationDirPath());
    qDebug() << im_open_decoder(
                    QString("%1/%2").arg(dir).arg(DefInfo::sys_dict).toUtf8().data(),
                    QString("%1/%2").arg(dir).arg(DefInfo::user_dict).toUtf8().data());
    im_set_max_lens(MaxLimt::spelling_len, MaxLimt::decoded_len);
    im_reset_search();
        int count = 0;
        char buf[] = {0x20,0x20,0xe5,0xb0,0x8f,0xe7,0xb1,0xb3,0xe5,0x85,0xb1,0xe4,0xba,0xab,0x57,0x69,0x46,0x69,0x5f,0x42,0x38,0x37,0x38};
//                "\x2020e5b08fe7b1b3e585b1e4baab576946695f42383738";
        qDebug() << "buf:" << QString(buf);
    while(1)
    {
        qDebug() << "--------please enter the character------\n\tInput:";
        QTextStream in(stdin);
        QString str;
        in >> str;
        QByteArray data = str.toUtf8();
        size_t cand_num = 0;
//        if (count == 0)
//            cand_num = im_search(data.constData(), data.size());
//        else
            cand_num = im_add_letter(*(str.toUtf8().data()));
        count ++;
        qDebug() << cand_num;
        //    size_t single = 0;
        //    size_t multi = 0;
        char16 *cand_buf = new char16[MaxLimt::decoded_len];
        size_t decode_len;
        qDebug() << "current_spl = " << im_get_sps_str(&decode_len);
        QString cand_str;
        char16 *cand;
        for (unsigned i = 0; i < cand_num; i++)
        {
            cand = im_get_candidate(i, cand_buf, MaxLimt::decoded_len);
            if (cand)
            {
                cand_str = QString::fromUtf16(cand);
                qDebug() << "fixed_len = " << im_get_fixed_len();
                //            if (i == 0) cand_str.remove(0, im_get_fixed_len());
            }
            else
            {
                cand_str = "";
            }
            qDebug() << cand_str;
        }

    }
    return app.exec();
}
