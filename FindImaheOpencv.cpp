
    Mat &org = *(Mat *) lpOrgPicture;
    Mat &tpl = *(Mat *) lpTemplate;
    Mat result;
    static const int matchMethod = TM_CCORR_NORMED;
    matchTemplate(org, tpl, result, matchMethod);
    double minValue = 0.0, maxValue = 0.0;
    Point minLoc, maxLoc;
    Point matchLoc;
    minMaxLoc(result, &minValue, &maxValue, &minLoc, &maxLoc);
    if (matchMethod == CV_TM_SQDIFF || matchMethod == CV_TM_SQDIFF_NORMED) {
        matchLoc = minLoc;
    } else {
        matchLoc = maxLoc;
    }
    tpl.release();
    result.release();
//    LOGE("double minValue= %lf maxValue = %lf", fabs(minValue), maxValue);
    char *tmpstr = new char[1000];
    sprintf(tmpstr, "%d,%d,%lf,%lf", matchLoc.x, matchLoc.y, maxValue, minValue);
    jstring rtstr = env->NewStringUTF(tmpstr);
    minValue = 0.0;
    maxValue = 0.0;