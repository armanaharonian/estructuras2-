for f in tests/ejercicio1/*.in.txt; do
  base="${f%.in.txt}"
  ./ejercicio1 < "$f" > mi_salida.txt
  if diff -q mi_salida.txt "${base}.out.txt" > /dev/null; then
    echo "$base: OK ✓"
  else
    echo "$base: FALLO ✗"
  fi
done