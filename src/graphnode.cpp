#include<iostream>

#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
 // std::cout<<"GraphNode::MoveChatbotHere"<<std::endl;
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
  // std::cout<<"EOF GraphNode::MoveChatbotHere"<<std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
 //  std::cout<<"GraphNode::MoveChatbotToNewNode"<<std::endl;
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
 // std::cout<<"EOF GraphNode::MoveChatbotToNewNode"<<std::endl;
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
//std::cout<<"GraphNode::GetChildEdgeAtIndex"<<std::endl;
    return _childEdges[index].get();
//std::cout<<"EOF GraphNode::GetChildEdgeAtIndex"<<std::endl;
    ////
    //// EOF STUDENT CODE
}