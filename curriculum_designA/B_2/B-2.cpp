#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
double MSE(double x1, double x2)
{
    return (x1 - x2) * (x1 - x2);
}//计算均方误差损失
class Network {
private:
    int epoches;//训练次数
    double learning_rate;//学习率
    double w1, w2, w3, w4, w5, w6, b1, b2, b3;//网络参数
public:
    Network(int epo, double rate) : epoches(epo), learning_rate(rate)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        w1 = ((double)rand() / RAND_MAX) * 2 - 1;
        w2 = ((double)rand() / RAND_MAX) * 2 - 1;
        w3 = ((double)rand() / RAND_MAX) * 2 - 1;
        w4 = ((double)rand() / RAND_MAX) * 2 - 1;
        w5 = ((double)rand() / RAND_MAX) * 2 - 1;
        w6 = ((double)rand() / RAND_MAX) * 2 - 1;
        b1 = ((double)rand() / RAND_MAX) * 2 - 1;
        b2 = ((double)rand() / RAND_MAX) * 2 - 1;
        b3 = ((double)rand() / RAND_MAX) * 2 - 1;//生成随机数，初始化连接权值和偏置值
    }
    double sigmoid(double x)
    {
        return 1.0 / (1 + exp(-x));
    }//激活函数

    double deriv_sigmoid(double x)
    {
        double y = sigmoid(x);
        return y * (1 - y);
    }//激活函数求导
    double forward(vector<double> data)
    {
        double h1 = sigmoid(w1 * data[0] + w2 * data[1] + b1);
        double h2 = sigmoid(w3 * data[0] + w4 * data[1] + b2);
        double o1 = sigmoid(w5 * h1 + w6 * h2 + b3);
        return o1;
    }//前向传播函数
    void train(vector<vector<double>> data, vector<double> label)
    {
        int total = data.size();
        for (int epo = 0; epo < epoches; epo++)
            {
            double total_loss = 0.0;
            for (int i = 0; i < total; ++i)
            {
                vector<double> x = data[i];
                double h1=sigmoid(w1 * x[0] + w2 * x[1] + b1);
                double h2=sigmoid(w3 * x[0] + w4 * x[1] + b2);//隐藏层的输出
                double o1=sigmoid(w5 * h1 + w6 * h2 + b3);//输出层的输出
                double pre=o1;
                double loss_pre = pre - label[i];//预测与实际的误差
                double pre_w5 = h1 * deriv_sigmoid(w5 * h1 + w6 * h2 + b3);
                double pre_w6 = h2 * deriv_sigmoid(w5 * h1 + w6 * h2 + b3);
                double pre_b3 = deriv_sigmoid(w5 * h1 + w6 * h2 + b3);
                double pre_h1 = w5 * deriv_sigmoid(w5 * h1 + w6 * h2 + b3);
                double pre_h2 = w6 * deriv_sigmoid(w5 * h1 + w6 * h2 + b3);
                double h1_w1 = x[0] * deriv_sigmoid(w1 * x[0] + w2 * x[1] + b1);
                double h1_w2 = x[1] * deriv_sigmoid(w1 * x[0] + w2 * x[1] + b1);
                double h1_b1 = deriv_sigmoid(w1 * x[0] + w2 * x[1] + b1);
                double h2_w3 = x[0] * deriv_sigmoid(w3 * x[0] + w4 * x[1] + b2);
                double h2_w4 = x[1] * deriv_sigmoid(w3 * x[0] + w4 * x[1] + b2);
                double h2_b2 = deriv_sigmoid(w3 * x[0] + w4 * x[1] + b2);
                w1 -= learning_rate * loss_pre * pre_h1 * h1_w1;
                w2 -= learning_rate * loss_pre * pre_h1 * h1_w2;
                b1 -= learning_rate * loss_pre * pre_h1 * h1_b1;
                w3 -= learning_rate * loss_pre * pre_h2 * h2_w3;
                w4 -= learning_rate * loss_pre * pre_h2 * h2_w4;
                b2 -= learning_rate * loss_pre * pre_h2 * h2_b2;
                w5 -= learning_rate * loss_pre * pre_w5;
                w6 -= learning_rate * loss_pre * pre_w6;
                b3 -= learning_rate * loss_pre * pre_b3;//更新连接权值和偏置值，随机梯度下降（SGD）
                total_loss += MSE(pre, label[i]);
            }
            if (epo % 10 == 0)
                {
                cout << "epoch " << epo << " loss: " << fixed << setprecision(6) << total_loss / total << endl;
                }
        }
    }//训练函数
    void predict(vector<vector<double>> test_data, vector<double> test_label)
    {
        int n = test_data.size();
        double cnt = 0;
        for (int i = 0; i < n; ++i)
            {
            double pre = forward(test_data[i]);
            pre = pre > 0.5? 1 : 0;
            cnt += (test_label[i] == pre);
            }
        cout << "correct rate: " << (int)(cnt/n) << endl;
    }//预测函数
};
void TrainData(vector<vector<double>>& data, vector<double>& label)
{
    data = { {-2,-1},{25,6},{17,4},{-15,-6} };
    label = { 1,0,0,1 };
}//加载训练数据
void TestData(vector<vector<double>>& test_data, vector<double>& test_label)
{
    test_data = { {-3,-4},{-5,-4},{12,3},{-13,-4},{9,12} };
    test_label = { 1,1,0,1,0 };
}//加载测试数据
int main() {
    vector<vector<double>> data;
    vector<double> label;
    TrainData(data, label);
    Network network(1000, 0.1);
    network.train(data, label);
    vector<vector<double>> test_data;
    vector<double> test_label;
    TestData(test_data, test_label);
    network.predict(test_data, test_label);
    return 0;
}
