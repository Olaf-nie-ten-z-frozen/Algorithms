#include<iostream>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin.tie(nullptr);
    int n,m;
    int unsigned priority1, priority2, priority3;
    int unsigned skill, skill_max = 0;
    int unsigned speed, speed_max=0;
    float height, height_max=0;
    std::string name, name_max;
    //cout<<"wpisz ilosc wiosek"<<endl;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        //cout<<"wpisz ilosc ludzi w "<<i+1<<" wiosce"<<endl;
        std::cin >> m;
        //cout<<"Wpisz priorytet 1, 2, 3:\n";
        cin>>priority1>>priority2>>priority3;
        for (int j = 0; j < m; j++){
            //cout<<"Wpisz imie, umiejetnosci, predkosc, wzrost: ";
            std::cin >> name >> skill >> height >> speed;
            switch(priority1){
                case 1:
                if(skill > skill_max){
                        height_max = height;
                        speed_max = speed;
                        skill_max = skill;
                        name_max = name;
                    }
                else if(skill == skill_max){
                    switch(priority2){
                        case 2:
                        if(height == height_max){
                                if(speed > speed_max){
                                    name_max = name;
                                    speed_max = speed;
                                }
                            }
                        else if(height > height_max){
                            name_max = name;
                            speed_max = speed;
                            height_max = height;
                        }
                        case 3:
                        if(speed == speed_max){
                                if(height > height_max){
                                    name_max = name;
                                    height_max = height;
                                }
                            }else if(speed>speed_max){
                                name_max = name;
                                speed_max = speed;
                                height_max = height;
                            }
                        }
                    }
                    break;
            case 2:
            if(height > height_max){
                    height_max = height;
                    speed_max = speed;
                    skill_max = skill;
                    name_max = name;
                }
                else if(height == height_max){
                    switch(priority2){
                        case 1:
                        if(skill == skill_max){
                                if(height > height_max){
                                    name_max = name;
                                    height_max = height;
                                }
                            }
                        else if(skill > skill_max){
                            name_max = name;
                            height_max = height;
                            skill_max = skill;
                        }
                        case 3:
                        if(speed == speed_max){
                                if(skill > skill_max){
                                    name_max = name;
                                    skill_max = skill;
                                }
                            }else if(speed>speed_max){
                                name_max = name;
                                speed_max = speed;
                                skill_max = skill;
                            }
                        }
                    }
                break;
            case 3:
            if(speed > speed_max){
                    height_max = height;
                    speed_max = speed;
                    skill_max = skill;
                    name_max = name;
                }
                else if(speed == speed_max){
                    switch(priority2){
                        case 1:
                        if(skill == skill_max){
                                if(height > height_max){
                                    name_max = name;
                                    height_max = height;
                                }
                        }else if(skill > skill_max){
                            name_max = name;
                            height_max = height;
                            skill_max = skill;
                        }
                        case 2:
                        if(height == height_max){
                                if(skill > skill_max){
                                    name_max = name;
                                    skill_max = skill;
                                }
                            }else if(height>height_max){
                                name_max = name;
                                height_max = height;
                                skill_max = skill;
                            }
                        
                    }
                }
                break;
            default:
                break;
            }
        }
        cout << name_max <<endl;
        name_max = "";
        skill_max = 0;
        height_max = 0;
        speed_max = 0;
    }
    
    return 0;
}