#pragma once



class CompoundTagUpdaterBuilder {

public:

    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&)const;
    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&);
    void addCompound(std::string const&)const;
    void addCompound(std::string const&);
    CompoundTagUpdaterBuilder(CompoundTagUpdater &);
    void match(std::string const&, std::string);
    void visit(std::string const&);
    void popVisit();
    void edit(std::string const&, std::function<void ()(CompoundTagEditHelper &)> &&);
    void tryEdit(std::string const&, std::function<void ()(CompoundTagEditHelper &)> &&);
    void remove(std::string const&);
    void rename(std::string const&, std::string const&);
};