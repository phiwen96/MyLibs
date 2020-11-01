#pragma once
#include <unordered_map>
#include "../../src/common.hpp"
//#include "authentication/Authenticator.hpp"
//#include "authentication/AuthenticatorState.hpp"
#include <ph/authentication/AbstractAuthenticator.hpp>
#include <ph/authentication/AuthenticatorState.hpp>
using namespace std;




namespace ph::authentication{




template <typename Key, typename Value>
class Authenticator : public AbstractAuthenticator<Key, Value, AbstractAuthenticatorState<Key, Value>>
{
using Self = Authenticator<Key, Value>;
using Base = AbstractAuthenticator<Key, Value, AbstractAuthenticatorState<Key, Value>>;

      
      
public:
      
      Authenticator (const std::unordered_map<Key, Value>& key_value) : Base (key_value, Type<KeyNotAuthenticated<Key, Value>>()) {
            
      }
      
      virtual void processKey (const Key& key) {
            Base::processKey (key);
      }
      
      virtual void processValue (const Value& value) {
            Base::processValue (value);
      }
      
      bool authenticated () const {
            return Base::authenticated();
      }
      
      bool keyAuthenticated () const {
            return Base::keyAuthenticated ();
      }
      
      bool valueAuthenticated () const {
            return Base::valueAuthenticated();
      }
      
      friend ostream& operator<< (ostream& os, const Self& self) {
            return os << (const Base&)self;
      }
      
      
protected:
      
      virtual void _authenticatedChanged (bool) {
            
      }
      
      virtual void _keyAuthenticatedChanged (bool) {
            
      }
      
      virtual void _valueAuthenticatedChanged (bool) {
            
      }











};


}











