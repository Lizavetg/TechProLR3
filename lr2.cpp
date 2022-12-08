#include <iostream>
#include <random>
#include <vector> 
#include "D:\TechProLR3-1\LR3.cpp"
using namespace std;

class range {
public:
    float min;
    float max;
};

class sensors {
public:
    string name;
    string measurement_unit;
    range measurement_range;
    float m;
    float measure()
    {
        random_device rd;
        mt19937 e2(rd());
        uniform_real_distribution <> dist(measurement_range.min, measurement_range.max);
        return dist(e2);
    }
};

class complex_navigation_system {
    public:
        string name;
        int t;
        vector <sensors> B;


        void add_sensor(sensors Q,int i)
        {
            profiler sleep_guard;
    
   
            B.push_back(Q);
            cout << "name  ";
            cin>> B[i].name;

            if (B[i].name == "acc") {
                B[i].measurement_unit=" m/s^2 ";
                B[i].measurement_range.min=1;
                B[i].measurement_range.max=3;
                cout << " acc ";
            }

            if (B[i].name == "gyro") {
                B[i].measurement_unit = " rad/s ";
                B[i].measurement_range.min = 7;
                B[i].measurement_range.max = 8;
            }

            if (B[i].name == "pos") {
                B[i].measurement_unit = " m ";
                B[i].measurement_range.min =14;
                B[i].measurement_range.max = 16;
            }
            B[i].m = B[i].measure();
            cout << B[i].m;


           cout<<" ADD";
         
         this_thread::sleep_for(5s);
        };
  
        vector <float>   measure_acc( )
        {
            profiler sleep_guard2;
            vector <float> acc;
            for (int i = 0; i < B.size(); i++) {
                if (B[i].name == "acc")
                {             
                    acc.push_back(B[i].m);             
                }
            }

            for (int i = 0; i < acc.size(); i++) {
                cout << acc[i]<<" ";        
            }
           cout<<"ACC ";
 
            this_thread::sleep_for(5s);
            return acc;

        };
   
        vector <float> measure_gyro()
        {
            profiler sleep_guard3;
           vector <float> gyro;
     
           for (int i = 0; i < B.size(); i++) {
               if (B[i].name == "gyro")
               {
                   gyro.push_back(B[i].m);
               }
           }

           for (int i = 0; i < gyro.size(); i++) {
               cout <<gyro[i] << " ";
           }
           cout<<"GYRO  ";

  
            this_thread::sleep_for(5s);
           return gyro;

        };

        vector <float> measure_position() {
             profiler sleep_guard4;
             vector <float> pos;
       
            for (int i = 0; i < B.size(); i++) {
                if (B[i].name == "pos")
                {
                   pos.push_back(B[i].m);
                }
            }

            for (int i = 0; i < pos.size(); i++) {
                cout << pos[i] << " ";
            }
             cout<<"POS";
          
              this_thread::sleep_for(5s);
            return pos;

        };
   

   
        void list_sensors()
        {
             profiler sleep_guard5;
            for (int i = 0; i < B.size(); i++) {
                cout << B[i].name << " ";
            }
            cout << endl;
            cout<< "list";
            this_thread::sleep_for(5s);
         
        };

        void list_sensors_info()
        {
             profiler sleep_guard6;
            for (int i = 0; i < B.size(); i++) {
                cout << B[i].measure() << " min " << B[i].measurement_range.min << " max "<< B[i].measurement_range.max <<"  "<< B[i].measurement_unit;
            }
            cout << endl;
            cout<<"list info ";
            this_thread::sleep_for(5s);
         
        };
    

    
  
 
};

int main()
{
    complex_navigation_system A;
    sensors Q;
    A.add_sensor(Q,0);
    cout << endl;
    A.add_sensor(Q,1);
    cout << endl;
    A.add_sensor(Q, 2);
    cout << endl;
    A.list_sensors();
    cout << endl;

    cout << " acc ";
    A.measure_acc();
    cout << endl;

    cout << " gyro ";
    A.measure_gyro();
    cout << endl;

    cout << " pos ";
    A.measure_position();
cout << endl;
 A.list_sensors_info();

}