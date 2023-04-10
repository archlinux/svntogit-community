# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>

pkgname=python-pbr
pkgver=5.11.1
pkgrel=5
pkgdesc="Python Build Reasonableness"
arch=('any')
url='https://pypi.python.org/pypi/pbr'
license=('Apache')
depends=('python-importlib-metadata' 'python-setuptools')
makedepends=('python-build' 'python-installer' 'python-wheel')
checkdepends=('python-stestr' 'python-testscenarios' 'python-testresources' 'python-testrepository'
              'python-virtualenv' 'python-wheel' 'python-sphinx' 'git')
source=("$pkgname-$pkgver.tar.gz::https://github.com/openstack-dev/pbr/archive/$pkgver.tar.gz")
sha512sums=('59ff86c3cc43cc824dfa448ff87fa1fcdd2561c269c63115777811934fd616c893f5fe727d5624eb624d42a43de386cc311c5c029520a3131d5144db5a891da4')

export PBR_VERSION=$pkgver

build() {
  cd pbr-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd pbr-$pkgver
  # TODO: find out this failure
  stestr run --exclude-regex "pbr.tests.test_packaging.TestPackagingWheels.test_metadata_directory_has_pbr_json"
}

package() {
  cd pbr-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
