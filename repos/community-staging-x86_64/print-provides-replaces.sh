#!/bin/bash

. PKGBUILD

if [[ ! -d src/ghc-${pkgver}/libraries ]]; then
  echo "error: no directory src/ghc-${pkgver}/libraries: You must extract the source tarball under src/"
  exit 1
fi

declare -A exclude
# no Win32 cause we're not building on windows
exclude['Win32']=1
# no integer-simple because we use integer-gmp
exclude['integer-simple']=1
# extract excluded libraries from ghc.mk
for exclude_pkg in $(sed 's/PKGS_THAT_ARE_INTREE_ONLY := //p' -n src/ghc-${pkgver}/ghc.mk); do
  exclude[${exclude_pkg}]=1
done

cd src/ghc-${pkgver}

# $1 is the name of the field
# $2 is the string for the test, either '=' or '<'
# ..$@ are the files to search
print_var() {
  field=$1
  output_version=$2
  shift
  shift

  printf "  $field=("
  for path in $(ls $@); do
    dirname=$(echo $path | awk -F '/' '{ print $2 }')
    cabalfile=$(echo $path | awk -F '/' '{ print $3 }')
    cabalname=$(basename $cabalfile .cabal)
    [[ ${exclude[${dirname}]} ]] && continue
    version=$(awk 'tolower($0) ~ /^version:/ {print $2 }' $path)
    printf "'haskell-${cabalname,,}"
    [[ -n "$output_version" ]] && printf "$output_version$version"
    printf "'\n            "
  done
  printf "\033[1A'haskell-${cabalname,,}"
  [[ -n "$output_version" ]] && printf "$output_version$version"
  printf "')\n"
}

# For ghc-libs
print_var 'provides' '=' libraries/*/*.cabal libraries/{containers/containers,Cabal/Cabal}/*.cabal utils/ghc-pkg/*.cabal
print_var 'replaces' '' libraries/*/*.cabal libraries/{containers/containers,Cabal/Cabal}/*.cabal utils/ghc-pkg/*.cabal

# For ghc
print_var 'provides' '=' utils/{hpc,hsc2hs,haddock*,hp2ps}/*.cabal
print_var 'replaces' '' utils/{hpc,hsc2hs,haddock*,hp2ps}/*.cabal
