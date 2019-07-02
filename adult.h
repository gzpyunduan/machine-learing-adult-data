#ifndef _Adult
#define _Adult

#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int string_to_int(string str){
  int len = str.length();
  int res = 0;
  for (int i = 0; i < len; i++)
    res = res * 10 + str[i] - '0';
  return res;
}

enum workclass {Private, Self_emp_not_inc, Self_emp_inc, Federal_gov, Local_gov, State_gov, Without_pay, Never_worked, wUnknown};
enum education {Bachelors, Some_college, eleventh, HS_grad, Prof_school, Assoc_acdm, Assoc_voc, ninth, seventh_eighth, twelveth, Masters, first_fourth, tenth, Doctorate, fifth_sixth, Preschool, eUnknown};
enum marital_status {married_civ_spouse, Divorced, Never_married, Separated, Widowed, married_spouse_absent, married_AF_spouse, mUnknown};
enum occupation {Tech_support, Craft_repair, Other_service, Sales, Exec_managerial, Prof_specialty, Handlers_cleaners, Machine_op_inspct, Adm_clerical, Farming_fishing, Transport_moving, Priv_house_serv, Protective_serv, Armed_Forces, oUnknown};
enum relationship {Wife, Own_child, Husband, Not_in_family, Other_relative, Unmarried, reUnknown};
enum race {White, Asian_Pac_Islander, Amer_Indian_Eskimo, Other, Black, raUnknown};
enum native_country {United_States, Cambodia, England, Puerto_Rico, Canada, Germany, Outlying_US, India, Japan, Greece, South, China, Cuba, Iran, Honduras, Philippines, Italy, Poland, Jamaica, Vietnam, Mexico, Portugal, Ireland, France, Dominican_Republic, Laos, Ecuador, Taiwan, Haiti, Columbia, Hungary, Guatemala, Nicaragua, Scotland, Thailand, Yugoslavia, El_Salvador, Trinadad_Tobago, Peru, Hong, Holand_Netherlands, nUnknown};

struct adult {
  int attr[15];

  adult(string line){
    int len = line.length();
    int last = 0;

    string str;
    for (int i = 0, j = 0; i < len; i++){
      if (line[i] == ','){
        str = line.substr(last, i - last);
        last = i + 2;
        //cout << str << endl;
        switch(j){
          case 0:
            attr[0] = string_to_int(str);
          case 1:
            if (str == "Private")
              attr[1] = Private;
            else if (str == "Self-emp-not-inc")
              attr[1] = Self_emp_not_inc;
            else if (str == "Self-emp-inc")
              attr[1] = Self_emp_inc;
            else if (str == "Federal-gov")
              attr[1] = Federal_gov;
            else if (str == "Local-gov")
              attr[1] = Local_gov;
            else if (str == "State-gov")
              attr[1] = State_gov;
            else if (str == "Without-pay")
              attr[1] = Without_pay;
            else if (str == "Never-worked")
              attr[1] = Never_worked;
            else
              attr[1] = wUnknown;
            break;
          case 2:
            attr[2] = string_to_int(str) / 100000;
            break;
          case 3:
              if (str == "Bachelors")
                attr[3] = Bachelors;
              else if (str == "Some-college")
                attr[3] = Some_college;
              else if (str == "11th")
                attr[3] = eleventh;
              else if (str == "HS-grad")
                attr[3] = HS_grad;
              else if (str == "Prof-school")
                attr[3] = Prof_school;
              else if (str == "Assoc-acdm")
                attr[3] = Assoc_acdm;
              else if (str == "Assoc-voc")
                attr[3] = Assoc_voc;
              else if (str == "9th")
                attr[3] = ninth;
              else if (str == "7th-8th")
                attr[3] = seventh_eighth;
              else if (str == "12th")
                attr[3] = twelveth;
              else if (str == "Masters")
                attr[3] = Masters;
              else if (str == "1st-4th")
                attr[3] = first_fourth;
              else if (str == "10th")
                attr[3] = tenth;
              else if (str == "Doctorate")
                attr[3] = Doctorate;
              else if (str == "5th-6th")
                attr[3] = fifth_sixth;
              else if (str == "Preschool")
                attr[3] = Preschool;
              else
                attr[3] = eUnknown;
            break;
          case 4:
            attr[4] = string_to_int(str);
            break;
          case 5:
              if (str == "married-civ-spouse")
                attr[5] = married_civ_spouse;
              else if (str == "Divorced")
                attr[5] = Divorced;
              else if (str == "Never-married")
                attr[5] = Never_married;
              else if (str == "Separated")
                attr[5] = Separated;
              else if (str == "Widowed")
                attr[5] = Widowed;
              else if (str == "married-spouse-absent")
                attr[5] = married_spouse_absent;
              else if (str == "married-AF-spouse")
                attr[5] = married_AF_spouse;
              else
                attr[5] = mUnknown;
            break;
          case 6:
            if (str == "Tech-support")
              attr[6] = Tech_support;
            else if (str == "Craft-repair")
              attr[6] = Craft_repair;
            else if (str == "Other-service")
              attr[6] = Other_service;
            else if (str == "Sales")
              attr[6] = Sales;
            else if (str == "Exec-managerial")
              attr[6] = Exec_managerial;
            else if (str == "Prof-specialty")
              attr[6] = Prof_specialty;
            else if (str == "Handlers-cleaners")
              attr[6] = Handlers_cleaners;
            else if (str == "Machine-op-inspct")
              attr[6] = Machine_op_inspct;
            else if (str == "Adm-clerical")
              attr[6] = Adm_clerical;
            else if (str == "Farming-fishing")
              attr[6] = Farming_fishing;
            else if (str == "Transport-moving")
              attr[6] = Transport_moving;
            else if (str == "Priv-house-serv")
              attr[6] = Priv_house_serv;
            else if (str == "Protective-serv")
              attr[6] = Protective_serv;
            else if (str == "Armed-Forces")
              attr[6] = Armed_Forces;
            else
              attr[6] = oUnknown;
            break;
          case 7:
            if (str == "Wife")
              attr[7] = Wife;
            else if (str == "Own-child")
              attr[7] = Own_child;
            else if (str == "Husband")
              attr[7] = Husband;
            else if (str == "Not-in-family")
              attr[7] = Not_in_family;
            else if (str == "Other-relative")
              attr[7] = Other_relative;
            else if (str == "Unmarried")
              attr[7] = Unmarried;
            else
              attr[7] = reUnknown;
            break;
          case 8:
            if (str == "White")
              attr[8] = White;
            else if (str == "Asian-Pac-Islander")
              attr[8] = Asian_Pac_Islander;
            else if (str == "Amer-Indian-Eskimo")
              attr[8] = Amer_Indian_Eskimo;
            else if (str == "Other")
              attr[8] = Other;
            else if (str == "Black")
              attr[8] = Black;
            else
              attr[8] = raUnknown;
            break;
          case 9:
            if (str == "Female")
              attr[9] = 0;
            else attr[9] = 1;
            break;
          case 10:
            attr[10] = string_to_int(str);
            break;
          case 11:
            attr[11] = string_to_int(str);
            break;
          case 12:
            attr[12] = string_to_int(str);
            break;
          case 13:
            if (str == "United-States")
              attr[13] = United_States;
            else if (str == "Cambodia")
              attr[13] = Cambodia;
            else if (str == "England")
              attr[13] = England;
            else if (str == "Puerto-Rico")
              attr[13] = Puerto_Rico;
            else if (str == "Canada")
              attr[13] = Canada;
            else if (str == "Germany")
              attr[13] = Germany;
            else if (str == "Outlying-US(Guam-USVI-etc)")
              attr[13] = Outlying_US;
            else if (str == "India")
              attr[13] = India;
            else if (str == "Japan")
              attr[13] = Japan;
            else if (str == "Greece")
              attr[13] = Greece;
            else if (str == "South")
              attr[13] = South;
            else if (str == "China")
              attr[13] = China;
            else if (str == "Cuba")
              attr[13] = Cuba;
            else if (str == "Iran")
              attr[13] = Iran;
            else if (str == "Honduras")
              attr[13] = Honduras;
            else if (str == "Philippines")
              attr[13] = Philippines;
            else if (str == "Italy")
              attr[13] = Italy;
            else if (str == "Poland")
              attr[13] = Poland;
            else if (str == "Jamaica")
              attr[13] = Jamaica;
            else if (str == "Vietnam")
              attr[13] = Vietnam;
            else if (str == "Mexico")
              attr[13] = Mexico;
            else if (str == "Portugal")
              attr[13] = Portugal;
            else if (str == "Ireland")
              attr[13] = Ireland;
            else if (str == "France")
              attr[13] = France;
            else if (str == "Dominican-Republic")
              attr[13] = Dominican_Republic;
            else if (str == "Laos")
              attr[13] = Laos;
            else if (str == "Ecuador")
              attr[13] = Ecuador;
            else if (str == "Taiwan")
              attr[13] = Taiwan;
            else if (str == "Haiti")
              attr[13] = Haiti;
            else if (str == "Columbia")
              attr[13] = Columbia;
            else if (str == "Hungary")
              attr[13] = Hungary;
            else if (str == "Guatemala")
              attr[13] = Guatemala;
            else if (str == "Nicaragua")
              attr[13] = Nicaragua;
            else if (str == "Scotland")
              attr[13] = Scotland;
            else if (str == "Thailand")
              attr[13] = Thailand;
            else if (str == "Yugoslavia")
              attr[13] = Yugoslavia;
            else if (str == "El-Salvador")
              attr[13] = El_Salvador;
            else if (str == "Trinadad&Tobago")
              attr[13] = Trinadad_Tobago;
            else if (str == "Peru")
              attr[13] = Peru;
            else if (str == "Hong")
              attr[13] = Hong;
            else if (str == "Holand-Netherlands")
              attr[13] = Holand_Netherlands;
            else
              attr[13] = nUnknown;
            break;
        }
        j++;
      }
      else if (line[i] == '<'){
        attr[14] = 0;
        break;
      }
      else if (line[i] == '>'){
        attr[14] = 1;
        break;
      }
    }

  }
};

#endif
