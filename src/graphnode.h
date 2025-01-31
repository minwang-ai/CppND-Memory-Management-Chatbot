#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    ChatBot _chatBot;  // used as a communication handle between GUI and ChatBot instance.

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }
    ChatBot* GetChatBotHandle() { return &_chatBot; }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentEdge(GraphEdge *edge);
    void AddEdgeToChildEdge(std::unique_ptr<GraphEdge> edge);

    //// STUDENT CODE
    ////
	
    void MoveChatbotHere(ChatBot chatbot); // should use passing by rvalue reference here due to; using passing by value just for printing order in task.5

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */