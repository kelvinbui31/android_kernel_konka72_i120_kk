
//#ifndef _MTK_CUSTOM_PROJECT_HAL_IMGSENSOR_SRC_CONFIGFTBL__H_
//#define _MTK_CUSTOM_PROJECT_HAL_IMGSENSOR_SRC_CONFIGFTBL__H_
#if 1
//


FTABLE_DEFINITION(SENSOR_DRVNAME_GC0329_YUV)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
FTABLE_SCENE_INDEP()
    //==========================================================================
#if 1
    //  Scene Mode
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_SCENE_MODE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::SCENE_MODE_AUTO), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::SCENE_MODE_AUTO,           
                MtkCameraParameters::SCENE_MODE_NIGHT,          
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Effect
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_EFFECT), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::EFFECT_NONE), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::EFFECT_NONE,       
                MtkCameraParameters::EFFECT_MONO,   
                MtkCameraParameters::EFFECT_NEGATIVE,
                MtkCameraParameters::EFFECT_SEPIA,      
                MtkCameraParameters::EFFECT_SEPIA_BLUE, 
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Picture Size (Both width & height must be 16-aligned)
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_PICTURE_SIZE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_("640x480"), 
            ITEM_AS_VALUES_(
                "320x240","640x384","640x480",/*      "800x480",      "1024x768",      "1280x768",      "1600x1200" *//*zhao.li@tcl 13.5.27 add 800x480 1280x768 for Bug 459062*/
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Preview Size
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_PREVIEW_SIZE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_("320x240"), 
            ITEM_AS_VALUES_(
                "176x144","320x240","352x288","640x384","640x480",/*"720x480","800x480",*//*zhao.li@tcl 13.5.27 add 800x480 for Bug 459062*/
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Video Size
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_VIDEO_SIZE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_("320x240"), 
            ITEM_AS_VALUES_(
                "176x144","320x240","352x288","640x384","640x480",/*"720x480","800x480", *//*zhao.li@tcl 13.5.27 add 800x480 for Bug 459062*/
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Preview Frame Rate Range
    FTABLE_CONFIG_AS_TYPE_OF_USER(
        KEY_AS_(MtkCameraParameters::KEY_PREVIEW_FPS_RANGE), 
        SCENE_AS_DEFAULT_SCENE(
           //zhao.li@tcl ITEM_AS_DEFAULT_("30000,30000"), 
            ITEM_AS_DEFAULT_("12000,12000"), 
            ITEM_AS_USER_LIST_(
                "(12000,12000)", 
                "(15000,15000)", 
                //"(30000,30000)", 
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Exposure Compensation
    FTABLE_CONFIG_AS_TYPE_OF_USER(
        KEY_AS_(MtkCameraParameters::KEY_EXPOSURE_COMPENSATION), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_("0"), 
            ITEM_AS_USER_LIST_(
                "-1",       //min exposure compensation index
                "1",        //max exposure compensation index
                "1.0",      //exposure compensation step; EV = step x index
            )
        ), 
        //......................................................................
        #if 1   //  SCENE HDR
        SCENE_AS_(MtkCameraParameters::SCENE_MODE_HDR, 
            ITEM_AS_DEFAULT_("0"), 
            ITEM_AS_USER_LIST_(
                "0",        //min exposure compensation index
                "0",        //max exposure compensation index
                "1.0",      //exposure compensation step; EV = step x index
            )
        )
        #endif
        //......................................................................
    )
#endif
    //==========================================================================
#if 1
    //  Anti-banding (Flicker)
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_ANTIBANDING), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::ANTIBANDING_OFF), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::ANTIBANDING_OFF, 
                MtkCameraParameters::ANTIBANDING_50HZ, 
                MtkCameraParameters::ANTIBANDING_60HZ, 
//                MtkCameraParameters::ANTIBANDING_AUTO, 
            )
        ), 
    )
#endif
    //==========================================================================
#if 0//zhao.li@tcl del for cts Bug 459993
    //  Video Snapshot
    FTABLE_CONFIG_AS_TYPE_OF_USER(
        KEY_AS_(MtkCameraParameters::KEY_VIDEO_SNAPSHOT_SUPPORTED), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::TRUE), 
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Video Stabilization (EIS)
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_SUPPORTED(
        KEY_AS_(MtkCameraParameters::KEY_VIDEO_STABILIZATION), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::FALSE), 
            ITEM_AS_SUPPORTED_(
            #if 1
                MtkCameraParameters::FALSE
            #else
                MtkCameraParameters::TRUE
            #endif
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Zoom
    FTABLE_CONFIG_AS_TYPE_OF_USER(
        KEY_AS_(MtkCameraParameters::KEY_ZOOM), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_("0"),  //Zoom Index
            ITEM_AS_USER_LIST_(
                //Zoom Ratio
                "100", "114", "132", "151", "174", 
                "200", "229", "263", "303", "348", 
                "400", 
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  Zsd
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_ZSD_MODE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::OFF), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::OFF, 
            )
        ), 
    )
#endif
    //==========================================================================
#if 1
    //  (Shot) Capture Mode
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_CAPTURE_MODE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::CAPTURE_MODE_NORMAL), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::CAPTURE_MODE_NORMAL, 
                //MtkCameraParameters::CAPTURE_MODE_FACE_BEAUTY, //zhao.li@tcl delete face beauty for bug 461791
                MtkCameraParameters::CAPTURE_MODE_CONTINUOUS_SHOT, //zhao.li@tcl 13.5.27 add continuous shots for Bug 459062 
            )
        ), 
    )
#endif
    //==========================================================================
END_FTABLE_SCENE_INDEP()
//------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
FTABLE_SCENE_DEP()
    //==========================================================================
#if 1
    //  Focus Mode
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_FOCUS_MODE), 
        SCENE_AS_DEFAULT_SCENE(
            //zhao.li@tcl bug 506434  ITEM_AS_DEFAULT_(MtkCameraParameters::FOCUS_MODE_AUTO), 
            ITEM_AS_DEFAULT_(MtkCameraParameters::FOCUS_MODE_INFINITY), 
            ITEM_AS_VALUES_(
            //zhao.li@tcl bug 506434      MtkCameraParameters::FOCUS_MODE_AUTO,   
                MtkCameraParameters::FOCUS_MODE_INFINITY, 
                MtkCameraParameters::FOCUS_MODE_CONTINUOUS_PICTURE, 
                MtkCameraParameters::FOCUS_MODE_CONTINUOUS_VIDEO, 
            )
        ), 
        //......................................................................
    )
#endif
    //==========================================================================
#if 1
    //  ISO
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_ISO_SPEED), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_("auto"), 
            ITEM_AS_VALUES_(
                "auto", 
            )
        ), 
        //......................................................................
    )
#endif
    //==========================================================================
#if 1
    //  White Balance.
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_WHITE_BALANCE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::WHITE_BALANCE_AUTO), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::WHITE_BALANCE_AUTO,            MtkCameraParameters::WHITE_BALANCE_INCANDESCENT, 
                MtkCameraParameters::WHITE_BALANCE_DAYLIGHT,        MtkCameraParameters::WHITE_BALANCE_CLOUDY_DAYLIGHT, 
                MtkCameraParameters::WHITE_BALANCE_FLUORESCENT,     MtkCameraParameters::WHITE_BALANCE_TUNGSTEN, 
            )
        ), 
        //......................................................................
    )
#endif
    //==========================================================================
#if 0
    //  ISP Edge
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_EDGE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::MIDDLE), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::LOW, MtkCameraParameters::MIDDLE, MtkCameraParameters::HIGH, 
            )
        ), 
        //......................................................................
        //......................................................................
    )
#endif
    //==========================================================================
#if 0
    //  ISP Hue
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_HUE), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::MIDDLE), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::LOW, MtkCameraParameters::MIDDLE, MtkCameraParameters::HIGH, 
            )
        ), 
        //......................................................................
        //......................................................................
    )
#endif
    //==========================================================================
#if 0
    //  ISP Saturation
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_SATURATION), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::MIDDLE), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::LOW, MtkCameraParameters::MIDDLE, MtkCameraParameters::HIGH, 
            )
        ), 
        //......................................................................
        //......................................................................
    )
#endif
    //==========================================================================
#if 0
    //  ISP Brightness
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_BRIGHTNESS), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::MIDDLE), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::LOW, MtkCameraParameters::MIDDLE, MtkCameraParameters::HIGH, 
            )
        ), 
        //......................................................................
        //......................................................................
    )
#endif
    //==========================================================================
#if 0
    //  ISP Contrast
    FTABLE_CONFIG_AS_TYPE_OF_DEFAULT_VALUES(
        KEY_AS_(MtkCameraParameters::KEY_CONTRAST), 
        SCENE_AS_DEFAULT_SCENE(
            ITEM_AS_DEFAULT_(MtkCameraParameters::MIDDLE), 
            ITEM_AS_VALUES_(
                MtkCameraParameters::LOW, MtkCameraParameters::MIDDLE, MtkCameraParameters::HIGH, 
            )
        ), 
        //......................................................................
        //......................................................................
    )
#endif
    //==========================================================================
END_FTABLE_SCENE_DEP()
//------------------------------------------------------------------------------
END_FTABLE_DEFINITION()


#endif
//#endif //_MTK_CUSTOM_PROJECT_HAL_IMGSENSOR_SRC_CONFIGFTBL__H_
