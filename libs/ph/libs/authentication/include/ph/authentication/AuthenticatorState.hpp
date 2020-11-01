#pragma once
//#include "authentication/Authenticator.hpp"
#include "authentication/AbstractAuthenticatorState.hpp"

namespace ph::authentication{






template <typename Key, typename Value = typename Key::Value>
struct KeyNotAuthenticated;
template <typename Key, typename Value = typename Key::Value>
struct KeyAuthenticated;
template <typename Key, typename Value = typename Key::Value>
struct Authenticated;


template <typename Key, typename Value>
struct KeyNotAuthenticated : AbstractAuthenticatorState<Key, Value>
{
      using Base = AbstractAuthenticatorState<Key, Value>;
      using Auth = typename Base::Auth;
      
      KeyNotAuthenticated (Auth& authenticator) : Base (authenticator)
      {
            
      }
      
      virtual ~KeyNotAuthenticated ()
      {
            
      }
      
      void processKey (const Key& key) // email
      {
            auto value = Base::find (key);
            if ( value.has_value() ) {
                  //                  const Value& v = value.value();
                  Base::template changeState<KeyAuthenticated<Key, Value>>(value.value());
            }
            
      }
      
      virtual bool keyAuthenticated () const
      {
            return false;
      }
      
      virtual bool valueAuthenticated () const
      {
            return false;
      }
      
      virtual void print (ostream& os) const
      {
            os << "KeyNotAuthenticated";
      }
};



template <typename Key, typename Value>
struct KeyAuthenticated : AbstractAuthenticatorState<Key, Value>
{
      using Base = AbstractAuthenticatorState<Key, Value>;
      using AbstractAuthenticatorState<Key, Value>::AbstractAuthenticatorState;
      
      template <typename Auth>
      KeyAuthenticated (const Value& value, Auth& auth) : m_value (value), Base (auth)
      {
            
      }
      
      virtual ~KeyAuthenticated ()
      {
            
      }
      
      void processKey (const Key& key) // email
      {
            Base::template changeStateAndProcessKey<KeyNotAuthenticated<Key, Value>>(key);
      }
      
      void processValue (const Value& value)
      {
            if ( m_value == value ) {
                  Base::template changeState<Authenticated<Key, Value>>(m_value);
            }
      }
      
      virtual bool keyAuthenticated () const
      {
            return true;
      }
      
      virtual bool valueAuthenticated () const
      {
            return false;
      }
      
      virtual void print (ostream& os) const
      {
            os << "KeyAuthenticated";
      }
      
private:
      Value m_value;
};

template <typename Key, typename Value>
struct Authenticated : AbstractAuthenticatorState<Key, Value>
{
      using Base = AbstractAuthenticatorState<Key, Value>;
      
      template <typename Auth>
      Authenticated (const Value& value, Auth& auth) : AbstractAuthenticatorState<Key, Value> (auth), m_value (value)
      {
            
      }
      
      void processKey (const Key& key) // email
      {
            Base::template changeStateAndProcessKey<KeyNotAuthenticated<Key, Value>>(key);
      }
      
      void processValue (const Value& value)
      {
            Base::template changeState<KeyAuthenticated<Key, Value>>(m_value);
      }
      
      virtual bool keyAuthenticated () const
      {
            return true;
      }
      
      virtual bool valueAuthenticated () const
      {
            return true;
      }
      
      virtual void print (ostream& os) const
      {
            os << "Authenticated";
      }
      
private:
      Value m_value;
};








}
