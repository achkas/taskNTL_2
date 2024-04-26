//Задача 2

#include <string>
#include <iostream>
#include <algorithm>



class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph :public DecoratedText 
{
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const 
    {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed :public DecoratedText
{    
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const
    {
        std::string var_data = data;
        std::reverse(var_data.begin(), var_data.end());        
        text_->render(var_data);
    }
};

class Link :public DecoratedText
{
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(const std::string& data, const std::string& data1) const
    {
        std::cout << "<a href = ";
        text_->render(data);
        std::cout << ">";
        text_->render(data1);
        std::cout << "</a>";
    }
};


int main()
{
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    std::cout << std::endl;    

    auto text_paragraph = new Paragraph(new Text());
    text_paragraph->render("Hello world");
    std::cout << std::endl;

    auto text_reversed = new Reversed(new Text());
    text_reversed->render("Hello world");
    std::cout << std::endl;

    auto text_link = new Link(new Text());
    text_link->render("netology.ru", "Hello world");

    delete text_block;
    delete text_paragraph;
    delete text_reversed;
    delete text_link;

    return 0;
}