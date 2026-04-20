#pragma once

template <class K, class V> class tabla {
  virtual void insertar(K clave, V valor) = 0;
  virtual bool buscar(K clave, V &valor) = 0;
  virtual void eliminar(K clave) = 0;
  virtual int cantidad() = 0;
};