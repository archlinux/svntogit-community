# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Limao Luo <luolimao+AUR@gmail.com>

pkgbase=python-pbr
pkgname=(python-pbr python2-pbr)
pkgver=5.0.0
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
sha512sums=('a85cd077aa058edccede7ce9653cb1039cae4f5eb09c01a4d1d185de3038839b105c85d738d5a56e66eb37af376e1596842b9bf4f4ff610dc66c56a07406f6ea')

prepare() {
  # Fix for new wheel
  sed -e 's/wheel.install/wheel.wheelfile/' \
      -e 's/wheel_file.zipfile/wheel_file/' \
      -i pbr-$pkgver/pbr/tests/test_packaging.py

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
