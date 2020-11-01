
class xcards
{
public:
      xcards (int argc, char** argv);
      int exec ();
      
private:
      QGuiApplication m_app;
      QQmlApplicationEngine m_engine;
};
