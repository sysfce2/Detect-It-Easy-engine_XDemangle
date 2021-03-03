// copyright (c) 2021 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include "xdemangle.h"

XDemangle::XDemangle(QObject *pParent) : QObject(pParent)
{

}

QString XDemangle::typeIdToString(XDemangle::TYPE type)
{
    QString sResult="Unknown"; // mb TODO translate

    switch(type)
    {
        case TYPE_UNKNOWN:      sResult=QString("Unknown");             break; // mb TODO translate
        case TYPE_MSVC:         sResult=QString("MSVC C++");            break;
        case TYPE_GCC_2XX:      sResult=QString("GCC 2.XX");            break;
        case TYPE_GCC_3XX:      sResult=QString("GCC 3.XX-X.XX");       break;
    }

    return sResult;
}

QString XDemangle::convert(QString sString,TYPE type)
{
    QString sResult;

    if(type==TYPE_MSVC)
    {
        sResult=convert_MSVC(sString);
    }

    // TODO

    return sResult;
}

QString XDemangle::convert_MSVC(QString sString)
{
    // ??$qbswap@$01@@YAPEAXPEBX_JPEAX@Z
    // ?qHash@@YAIABVQGeoCoordinate@@I@Z
    QString sResult;
    // All C++ begins with ?

    if(XBinary::isRegExpPresent("^\\?",sString)) // ? Customer type
    {
        sString=sString.mid(1,-1);
        // TODO Check digits
        if(XBinary::isRegExpPresent("^\\?\\$",sString)) // ?$
        {
            sResult="Test";
        }
    }

    return sResult;
}
