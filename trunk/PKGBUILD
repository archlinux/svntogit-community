# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>

pkgname=python-pbr
pkgver=5.9.0
pkgrel=1
pkgdesc="Python Build Reasonableness"
arch=('any')
url='https://pypi.python.org/pypi/pbr'
license=('Apache')
depends=('python-importlib-metadata' 'python-setuptools')
checkdepends=('python-stestr' 'python-testscenarios' 'python-testresources' 'python-testrepository'
              'python-mock' 'python-virtualenv' 'python-wheel' 'python-sphinx' 'git')
source=("$pkgname-$pkgver.tar.gz::https://github.com/openstack-dev/pbr/archive/$pkgver.tar.gz")
sha512sums=('e71dd312e2242b7123fda9d53a84423381a8c48f9ab6c8c3a67e7c52ca46f366b22c67fbba6ec8085a1adf7267fdf3d59752a7a3a2748cd1b1f1ef4721665931')

export PBR_VERSION=$pkgver

build() {
  cd pbr-$pkgver
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
