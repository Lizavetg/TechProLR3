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
        //    profiler sleep_guard;
            B.reserve(10000);
            B.push_back(Q);
          //  cout << "name  ";
          //  cin>> B[i].name;

            if (B[i].name == "acc") {
                B[i].measurement_unit=" m/s^2 ";
                B[i].measurement_range.min=1;
                B[i].measurement_range.max=3;
                // cout << " acc ";
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
            // cout << B[i].m;
            // cout<<" ADD";
        };
  
        vector <float>   measure_acc( )
        {
            //profiler sleep_guard2;
            vector <float> acc;
            // acc.reserve(100000);
            B.reserve(1000000);
            for (int i = 0; i < B.size(); i++) {
                if (B[i].name == "acc")
                {             
                    acc.push_back(B[i].m);             
                }
            }

            for (int i = 0; i < acc.size(); i++) {
               // cout << acc[i]<<" ";        
            }
        //    cout<<"ACC ";
 
           
            return acc;

        };
   
        vector <float> measure_gyro()
        {
           // profiler sleep_guard3;
           vector <float> gyro;
            B.reserve(100000);
           for (int i = 0; i < B.size(); i++) {
               if (B[i].name == "gyro")
               {
                   gyro.push_back(B[i].m);
               }
           }

           for (int i = 0; i < gyro.size(); i++) {
               //cout <<gyro[i] << " ";
           }
        //    cout<<"GYRO  ";

  
           
           return gyro;

        };

        vector <float> measure_position() {
            // profiler sleep_guard4;
             vector <float> pos;
             B.reserve(100000);
       
            for (int i = 0; i < B.size(); i++) {
                if (B[i].name == "pos")
                {
                   pos.push_back(B[i].m);
                }
            }

            for (int i = 0; i < pos.size(); i++) {
             //   cout << pos[i] << " ";
            }
            //  cout<<"POS  ";
          
              
            return pos;

        };
   

   
        void list_sensors()
        {
             //profiler sleep_guard5;
            for (int i = 0; i < B.size(); i++) {
                // cout << B[i].name << " ";
            }
            cout << endl;
            // cout<< "list";
            
         
        };

        void list_sensors_info()
        {
             //profiler sleep_guard6;
            for (int i = 0; i < B.size(); i++) {
            //    cout << B[i].measure() << " min " << B[i].measurement_range.min << " max "<< B[i].measurement_range.max <<"  "<< B[i].measurement_unit;
            }
            cout << endl;
           // cout<<"list info ";
           
         
        }; 
 
};

int main()
{
    complex_navigation_system A;
    sensors Q;
    {
        profiler sleep_guard;
        for(int i=0;i<10000;i++){
           // profiler sleep_guard;
            A.add_sensor(Q,0);
            A.B[0].name="acc";
        }
    }
    cout << endl;

    {
        profiler sleep_guard2;
        for(int i=0;i<10000;i++){
            A.add_sensor(Q,1);
            A.B[1].name="gyro";
        }
    }
    cout << endl;

    {
        profiler sleep_guard3;
        for(int i=0;i<10000;i++){
            A.add_sensor(Q, 2);
            A.B[2].name= "pos";
        }
    }
    cout << endl;
    // A.list_sensors();
    
    cout << endl;

    cout << " acc ";
    {
        profiler sleep_guard3;
        for(int i=0;i<10000;i++){
            A.measure_acc();
        }
    }


    cout << endl;

    cout << " gyro ";
     {
        profiler sleep_guard4;
        for(int i=0;i<10000;i++){
            A.measure_gyro();
        }
     }
    cout << endl;

    cout << " pos ";

    {
        profiler sleep_guard4;
        for(int i=0;i<10000;i++){
            A.measure_position();
        }
    }
    // A.list_sensors_info();

}