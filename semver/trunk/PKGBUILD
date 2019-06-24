# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=semver
pkgver=6.1.2
pkgrel=1
pkgdesc='The semantic version parser used by npm.'
arch=('any')
url='https://github.com/npm/node-semver'
license=('ISC')
depends=('nodejs')
makedepends=('npm')
source=(https://registry.npmjs.org/$pkgname/-/$pkgname-$pkgver.tgz)
noextract=($pkgname-$pkgver.tgz)
sha512sums=('cf83ea882a68986b568fceb7de87807579b52a7d56fbedd3f1ea646589f0895808608274407b338489d84894d8c5e6c1c901fb295084027f11f5dbb3656d8f85')

package() {
  npm install -g --user root --prefix "$pkgdir"/usr "$srcdir"/$pkgname-$pkgver.tgz

  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s ../../../lib/node_modules/$pkgname/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
