//домашняя директория проекта
static const char* PATH_PROJECT   =  "/home/ivan/TP_GameProject_CPP/";

//фон
static const char* PATH_BACKGROUND = "project_sprites/backgrounds/";
static const char* F_BACKGROUND = "background1.jpg";

//лестницы
static const char* PATH_STAIRCASES = "project_sprites/staircases/custom/";
static const char* F_STAIRCASE_SMALL = "staircaseSmall.png";
static const char* F_STAIRCASE_MEDIUM = "staircaseMedium.png";
static const char* F_STAIRCASE_LARGE = "staircaseLarge.png";
static const char* F_STAIRCASE_XLARGE = "staircaseXlarge.png";

//кубик
static const char* PATH_CUBE = "project_sprites/walls/";
static const char* F_CUBE1 = "cube1_20px";
static const char* F_CUBE2 = "cube2_20px";

char* generatePath(const char *leftPart, const char* rightPart, const char* fileName) {
    char *path = new char[127];
    strcpy(path, leftPart);
    strcat(path, rightPart);
    strcat(path, fileName);
    return path;
}
