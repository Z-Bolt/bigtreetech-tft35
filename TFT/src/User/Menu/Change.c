#include "Change.h"
#include "includes.h"

//1��title(����), ITEM_PER_PAGE��item(ͼ��+��ǩ)
const MENUITEMS changeItems = {
//   title
LABEL_CHANGE,
// icon                       label
 {{ICON_CHANGE,               LABEL_CHANGE},
  {ICON_X_HOME,               LABEL_X},
  {ICON_Y_HOME,               LABEL_Y},
  {ICON_Z_HOME,               LABEL_Z},
  {ICON_UNLOAD,               LABEL_UNLOAD},
  {ICON_LOAD,                 LABEL_LOAD},
  {ICON_BACKGROUND,           LABEL_BACKGROUND},
  {ICON_BACK,                 LABEL_BACK},}
};

void menuChange(void)
{
  KEY_VALUES key_num = KEY_IDLE;
  menuDrawPage(&changeItems);
  while(infoMenu.menu[infoMenu.cur] == menuChange)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0: storeCmd("G28\n");   break;
      case KEY_ICON_1: storeCmd("G28 X\n"); break;
      case KEY_ICON_2: storeCmd("G28 Y\n"); break;
      case KEY_ICON_3: storeCmd("G28 Z\n"); break;
      case KEY_ICON_7: infoMenu.cur--;      break;
      default:break;
    }
    loopProcess();
  }
}
