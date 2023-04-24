# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Bruno Galeotti <bgaleotti at gmail dot com>

_name=TypeScript
pkgname=typescript
pkgver=5.0.4
pkgrel=1
pkgdesc='JavaScript with syntax for types'
arch=('any')
url=http://www.typescriptlang.org
license=('Apache')
depends=('nodejs')
makedepends=('npm' 'rsync')
source=("https://github.com/microsoft/$_name/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
b2sums=('20565a208225fb9fcd5b5532296f94bf870b0452fb43c72a044e52e3a2e4a6f2af20119dbcb50f996c631ff87821c298c72fddd1289919f4463313c35b322049')

prepare() {
  cd $_name-$pkgver
  npm ci
}

build() {
  cd $_name-$pkgver
  npx hereby LKG
}

check() {
  cd $_name-$pkgver
  npm run test
}

package() {
  install -d "$pkgdir"/usr/{bin,lib/node_modules/$pkgname}
  ln -s ../lib/node_modules/$pkgname/bin/{tsc,tsserver} "$pkgdir"/usr/bin

  cd $_name-$pkgver
  rsync -r --exclude .gitattributes README.md SECURITY.md bin lib package.json \
    "$pkgdir"/usr/lib/node_modules/$pkgname
  install -Dt "$pkgdir"/usr/share/licenses/$pkgname ThirdPartyNoticeText.txt
}
