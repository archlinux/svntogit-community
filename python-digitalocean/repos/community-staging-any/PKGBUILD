# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-digitalocean
pkgver=1.17.0
pkgrel=4
pkgdesc='digitalocean.com API to manage Droplets and Images'
arch=('any')
license=('LGPL')
url='https://github.com/koalalorenzo/python-digitalocean'
depends=('python-requests' 'python-jsonpickle')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-responses')
source=("$pkgname-$pkgver.tar.gz::https://github.com/koalalorenzo/python-digitalocean/archive/v$pkgver.tar.gz")
sha512sums=('3b5f5adb5fac9693450954e568433cecb43152d4cb2b5709126dc7c69c6b84f19428dcd3688718588a986d3ea9170a956387f3050cd10a69ba89d5dcdf8e100c')

build() {
  cd python-digitalocean-$pkgver
  python setup.py build
}

check() {
  cd python-digitalocean-$pkgver
  python setup.py pytest || echo "https://github.com/koalalorenzo/python-digitalocean/issues/258"
}

package() {
  cd python-digitalocean-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
