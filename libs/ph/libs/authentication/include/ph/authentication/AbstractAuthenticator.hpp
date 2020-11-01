#pragma once
#include <unordered_map>
#include "../../src/common.hpp"
using namespace std;

namespace ph::authentication{





template <typename Key, typename Value, typename State>
class AbstractAuthenticator
{
      using Self = AbstractAuthenticator<Key, Value, State>;
      
public:
      
      template <typename ConcreteState>
      AbstractAuthenticator (const unordered_map<Key, Value>& map, Type<ConcreteState>) : m_map (map), m_state (new ConcreteState(*this)), m_authenticated(false), m_keyAuthenticated(false), m_valueAuthenticated(false)
      {
            
      }
      
      virtual void processKey (const Key& key)
      {
            m_state -> processKey (key);
            setKeyAuthenticated();
      }
      
      virtual void processValue (const Value& value)
      {
            m_state -> processValue (value);
            setValueAuthenticated();
      }
      
      bool authenticated () const
      {
            return keyAuthenticated() && valueAuthenticated();
      }
      
      bool keyAuthenticated () const
      {
            return m_state -> keyAuthenticated ();
      }
      
      bool valueAuthenticated () const
      {
            return m_state -> valueAuthenticated ();
      }
      
      friend ostream& operator<< (ostream& os, const Self& self)
      {
            os << *self.m_state;
            return os;
      }
      
protected:
      virtual void _authenticatedChanged (bool){
            
      }
      
      virtual void _keyAuthenticatedChanged (bool){
            
      }
      
      virtual void _valueAuthenticatedChanged (bool){
            
      }
      
      //signals:
      //      void authenticatedChanged ();
      //      void keyAuthenticatedChanged ();
      //      void valueAuthenticatedChanged ();
      
private:
      const unordered_map<Key, Value>& m_map;
      State* m_state;
      bool m_authenticated;
      bool m_keyAuthenticated;
      bool m_valueAuthenticated;
      
      Key m_currentKey;
      Value m_currentValue;
      
      void setAuthenticated ()
      {
            if(m_state->keyAuthenticated() && m_state->valueAuthenticated() == m_authenticated)
                  return;
            m_authenticated != m_authenticated;
            _authenticatedChanged(m_authenticated);
      }
      
      void setValueAuthenticated ()
      {
            if (m_state->valueAuthenticated() == m_valueAuthenticated)
                  return;
            m_valueAuthenticated != m_valueAuthenticated;
            _valueAuthenticatedChanged (m_valueAuthenticated);
            setAuthenticated();
      }
      
      void setKeyAuthenticated ()
      {
            if (m_state->keyAuthenticated() == m_keyAuthenticated)
                  return;
            m_keyAuthenticated != m_keyAuthenticated;
            _keyAuthenticatedChanged (m_keyAuthenticated);
            setAuthenticated();
      }
      
      friend State;
};







// EXAMPLE //
/**
 #include <authentication/AbstractAuthenticator.hpp>
 #include <authentication/AuthenticatorState.hpp>
 
 using namespace ph::authentication;
 
 unordered_map<std::string, std::string> mymap;
 mymap["philip.sve@hotmail.com"] = "snippa";
 mymap["oswe.sve@hotmail.com"] = "rosen";
 
 
 //      auth(string, string) a1 (mymap, new KeyNotAuthenticated<string, string>);
 
 
 AbstractAuthenticator<std::string, std::string, AbstractAuthenticatorState<std::string, std::string>> a (mymap, Type<KeyNotAuthenticated<string, string>>());
 cout << a.keyAuthenticated() << endl;
 cout << a.valueAuthenticated() << endl;
 a.processKey("philip.sve@hotmail.com");
 cout << a.keyAuthenticated() << endl;
 cout << a.valueAuthenticated() << endl;
 a.processValue("snippa");
 cout << a.keyAuthenticated() << endl;
 cout << a.valueAuthenticated() << endl;
 
 */






}

