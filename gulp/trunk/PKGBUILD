# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Micha Alt <micha.tucker at gmail dot com>

pkgname=gulp
pkgver=4.0.2
pkgrel=3
pkgdesc="The streaming build system"
arch=('any')
url="https://gulpjs.com/"
license=('MIT')
depends=('nodejs' 'semver')
makedepends=('npm')
source=("https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz")
noextract=($pkgname-$pkgver.tgz)
sha512sums=('76f12cdbb48266dda26c5dbdc588269f0c02619c5dc6143ff8b15695b016f32ee3b7af0bffae78d362f3dfe08acb43afe2b3acf8d111983abb62565a0ea5087c')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  mkdir -p "$pkgdir/usr/share/licenses/$pkgname"
  ln -s "../../../lib/node_modules/$pkgname/LICENSE" "$pkgdir/usr/share/licenses/$pkgname/"

  # Non-deterministic race in npm gives 777 permissions to random directories.
  # See https://github.com/npm/npm/issues/9359 for details.
  chmod -R u=rwX,go=rX "$pkgdir"

  # npm installs package.json owned by build user
  # https://bugs.archlinux.org/task/63396
  chown -R root:root "$pkgdir"

  # Experimental dedup
  cd "$pkgdir"/usr/lib/node_modules/$pkgname/node_modules
  for dep in semver; do
    rm -r $dep;
  done
}
