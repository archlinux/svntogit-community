# $Id$
# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=npm
pkgver=4.5.0
pkgrel=1
pkgdesc='A package manager for javascript'
arch=('any')
url='https://www.npmjs.com/'
license=('custom:Artistic')
depends=('nodejs' 'semver')
provides=('nodejs-node-gyp')
makedepends=('procps-ng' 'marked-man')
optdepends=('python2: for node-gyp')
options=('!emptydirs')
source=("$pkgname-$pkgver.tar.gz::https://github.com/npm/npm/archive/v$pkgver.tar.gz")
sha512sums=('e5b1f84c80316ff272024deb418c4c9f736649e58650816f4318c37617469902806e5252aa2301ad6bca59b3bcdaef8cfd9f7b9a2e48a8dddeb04d28eb4fdd43')

prepare() {
  cd npm-$pkgver
  ln -s /usr/bin/marked{,-man} node_modules/.bin/
}

build() {
  cd npm-$pkgver
  make
}

package() {
  cd npm-$pkgver
  make NPMOPTS="--prefix=\"$pkgdir/usr\"" install

  # Why 777? :/
  chmod -R u=rwX,go=rX "$pkgdir"

  # Fix files owned by nobody:
  chown -R root "$pkgdir"/usr/lib/node_modules

  # Fix wrong symlinks
  for _dir in man1 man5 man7; do
    mkdir -p "$pkgdir"/usr/share/man/$_dir
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
    node "$srcdir"/npm-$pkgver/cli.js link $dep;
  done

  install -Dm644 "$srcdir"/npm-$pkgver/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
