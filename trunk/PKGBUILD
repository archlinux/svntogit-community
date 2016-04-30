# $Id$
# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=npm
pkgver=3.8.8
pkgrel=1
pkgdesc='A package manager for javascript'
arch=('any')
url='https://www.npmjs.com/'
license=('custom:Artistic')
depends=('nodejs' 'semver')
provides=('nodejs-node-gyp')
makedepends=('git' 'procps-ng')
optdepends=('python2: for node-gyp')
options=('!emptydirs')
source=("git+https://github.com/npm/npm.git#tag=v$pkgver")
md5sums=('SKIP')

build() {
  cd npm
  make
}

package() {
  cd npm
  make NPMOPTS="--prefix=\"$pkgdir/usr\"" install

  # Why 777? :/
  chmod -R u=rwX,go=rX "$pkgdir"
  
  # Fix files owned by nobody:
  chown -R root "$pkgdir/usr/lib/node_modules" 

  # Fix wrong symlinks
  for _dir in man1 man5 man7; do
    rm -f "$pkgdir"/usr/share/man/$_dir/*
    cd "$pkgdir"/usr/lib/node_modules/npm/man/$_dir
    for _file in *; do
      ln -s /usr/lib/node_modules/npm/man/$_dir/$_file "$pkgdir"/usr/share/man/$_dir/
    done
  done
  
  # Provide node-gyp executable
  cp "$pkgdir"/usr/lib/node_modules/npm/bin/node-gyp-bin/node-gyp "$pkgdir"/usr/bin/node-gyp
  sed -i 's|"`dirname "$0"`/../../|"`dirname "$0"`/../lib/node_modules/npm/|' "$pkgdir"/usr/bin/node-gyp

  # Experimental dedup
  cd "$pkgdir"/usr/lib/node_modules/$pkgname/node_modules
  for dep in semver; do
    rm -r $dep;
    node "$srcdir"/npm/cli.js link $dep;
  done
  
  install -Dm644 "$srcdir/npm/LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
