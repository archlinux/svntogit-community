# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-betamax-serializers
pkgver=0.2.1
pkgrel=8
pkgdesc="A set of third-party serializers for Betamax"
arch=('any')
license=('Apache')
url='https://gitlab.com/betamax/serializers'
depends=('python-betamax')
makedepends=('python-setuptools')
source=("https://gitlab.com/betamax/serializers/-/archive/$pkgver/serializers-$pkgver.tar.bz2")
sha256sums=('62f3e00393a00ce52895253914261297ff14fdef9840f9cc9d7eb7388c405d4f')

package() {
  cd serializers-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
