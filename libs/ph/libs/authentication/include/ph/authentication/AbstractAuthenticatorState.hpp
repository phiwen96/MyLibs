#pragma once
#include <ph/authentication/AbstractAuthenticator.hpp>
#include <iostream>
using namespace std;

namespace ph::authentication{


template <typename Key, typename Value>
struct AbstractAuthenticatorState
{
      using Self = AbstractAuthenticatorState<Key, Value>;
      using Auth = AbstractAuthenticator<Key, Value, Self>;
      
      AbstractAuthenticatorState (Auth& authenticator) : m_authenticator(authenticator), m_map (authenticator.m_map), m_authenticated (false)
      {
            
      }
      
      virtual ~AbstractAuthenticatorState ()
      {
            
      }
      
      virtual void processKey (const Key& key) // email
      {
            
      }
      
      virtual void processValue (const Value& value) // email
      {
            
      }
      
      bool authenticated () const
      {
            return m_authenticated;
      }
      
      virtual bool keyAuthenticated () const = 0;
      
      virtual bool valueAuthenticated () const = 0;
      
      virtual void print (ostream& os) const
      {
            os << "State";
      }
      
      friend ostream& operator<< (ostream& os, const Self& self)
      {
            self.print (os);
            return os;
      }
      
      operator const Auth& ()
      {
            return m_authenticator;
      }
      
private:
      AbstractAuthenticator<Key, Value, Self>& m_authenticator;
      bool m_authenticated;
      
protected:
      const unordered_map<Key, Value>& m_map;
      
      
      template <typename NewConcreteState>
      void changeState ()
      {
            m_authenticator.m_state = new NewConcreteState (m_authenticator);
            delete this;
      }
      
      template <typename NewConcreteState, class T>
      void changeState (const T& t)
      {
            m_authenticator.m_state = new NewConcreteState (t, m_authenticator);
            delete this;
      }
      
      template <typename NewConcreteState>
      void changeState (NewConcreteState* state)
      {
            m_authenticator.m_state = state;
            delete this;
      }
      
      template <typename NewConcreteState>
      void changeStateAndProcessKey (const Key& key)
      {
            m_authenticator.m_state = new NewConcreteState (m_authenticator);
            m_authenticator.processKey(key);
            delete this;
      }
      
      template <typename NewConcreteState>
      void changeStateAndProcessValue (const Value& value)
      {
            m_authenticator.m_state = new NewConcreteState (m_authenticator);
            m_authenticator.processValue(value);
            delete this;
      }
      
      optional<Value> find (const Key& key)
      {
            typename unordered_map<Key, Value>::const_iterator i = m_map.find(key);
            
            if ( i != m_map.end() ) {
                  return (*i).second;
            }
            return {};
      }
      
};

}
