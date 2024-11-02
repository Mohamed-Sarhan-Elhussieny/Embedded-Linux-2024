#ifndef COMMAND_H
#define COMMAND_H

class COMMAND {
public:
    COMMAND();
    ~COMMAND();

    bool open_website(const std::string& website);
    void pc_orders(const std::string& cmd);
};

#endif
