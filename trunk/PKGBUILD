# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>

pkgbase=python-pbr
pkgname=(python-pbr python2-pbr)
pkgver=5.2.0
pkgrel=1
pkgdesc="Python Build Reasonableness"
arch=('any')
url='https://pypi.python.org/pypi/pbr'
license=('Apache')
makedepends=('python2-setuptools' 'python-setuptools' 'git')
checkdepends=('python-stestr' 'python2-stestr' 'python-testscenarios' 'python2-testscenarios'
              'python-testresources' 'python2-testresources' 'python-testrepository'
              'python2-testrepository' 'python-mock' 'python2-mock'
              'python-virtualenv' 'python2-virtualenv' 'python-wheel' 'python2-wheel'
              'python-sphinx' 'python2-sphinx')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/openstack-dev/pbr/archive/$pkgver.tar.gz")
sha512sums=('f75e1faef11035e161fa193d489ec052f2f0fd0b1832cb5fd20e491dc19d8cc9dd5f9fead5302c4e7f59a0fd7cb8d27090c11d92df558876e469316198a39e13')

prepare() {
  # Fix for new wheel
  sed -e 's/wheel.install/wheel.wheelfile/' \
      -e 's/wheel_file.zipfile/wheel_file/' \
      -i pbr-$pkgver/pbr/tests/test_packaging.py

  sed -i 's/packaging, distutils, setuptools/packaging,distutils,setuptools/' pbr-$pkgver/pbr/tests/test_core.py

  cp -a pbr-$pkgver{,-py2}

  find pbr-$pkgver-py2 -name \*.py -exec sed -i '1s/python$/&2/' {} +

  export PBR_VERSION=$pkgver
}

build() {
  cd "$srcdir"/pbr-$pkgver
  python setup.py build

  cd "$srcdir"/pbr-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/pbr-$pkgver
  stestr run

  cd "$srcdir"/pbr-$pkgver-py2
  PYTHON=python2 stestr2 run
}

package_python-pbr() {
  depends=('python-setuptools')

  cd pbr-$pkgver
  python setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-pbr() {
  depends=('python2-setuptools')

  cd pbr-$pkgver-py2
  python2 setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
  
  mv "$pkgdir"/usr/bin/pbr{,2}
}
