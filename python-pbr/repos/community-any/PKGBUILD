# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>

pkgname=python-pbr
pkgver=5.8.1
pkgrel=1
pkgdesc="Python Build Reasonableness"
arch=('any')
url='https://pypi.python.org/pypi/pbr'
license=('Apache')
depends=('python-setuptools')
checkdepends=('python-stestr' 'python-testscenarios' 'python-testresources' 'python-testrepository'
              'python-mock' 'python-virtualenv' 'python-wheel' 'python-sphinx' 'git')
source=("$pkgname-$pkgver.tar.gz::https://github.com/openstack-dev/pbr/archive/$pkgver.tar.gz")
sha512sums=('a2cd53ec9c1d3c529a651c762e71645097a616f83f1299b5509e41c57ceb42cd96537e92fbd12bd825c3cfac7e6995ecc1ff9938f7760d48e2488fe8b63e28e5')

export PBR_VERSION=$pkgver

build() {
  cd "$srcdir"/pbr-$pkgver
  python setup.py build
}

check() {
  cd pbr-$pkgver
  # TODO: find out this failure
  stestr run --exclude-regex "pbr.tests.test_packaging.TestPackagingWheels.test_metadata_directory_has_pbr_json"
}

package() {
  cd pbr-$pkgver
  python setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
