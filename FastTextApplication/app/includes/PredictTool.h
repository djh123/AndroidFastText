//
// Created by djh on 20-9-25.
//

#ifndef PREDICTAPI_H_
#define PREDICTAPI_H_

#include <vector>
#include <iostream>
#include<string>
class PredictTool
{
private:
    /* data */
public:
    PredictTool(/* args */);
    ~PredictTool();
    void loadModel(const std::string& filename);
    std::vector<std::pair<float, std::string>> predictProcess(std::string text, int topk, float threshold);

};




#endif