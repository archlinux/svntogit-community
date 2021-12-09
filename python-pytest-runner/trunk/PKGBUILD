# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pytest-runner
pkgver=5.3.1
pkgrel=3
pkgdesc="Invoke py.test as distutils command with dependency resolution"
arch=('any')
license=('MIT')
url="https://github.com/pytest-dev/pytest-runner"
depends=('python-pytest' 'python-setuptools')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-pytest-black' 'python-pytest-cov' 'python-pytest-virtualenv'
              'python-pytest-flake8' 'python-pytest-enabler')
source=("https://github.com/pytest-dev/pytest-runner/archive/v$pkgver/$pkgname-$pkgver.tar.gz"
        $pkgname-python310.patch::https://github.com/pytest-dev/pytest-runner/pull/59.patch)
sha512sums=('3b3197e86d64e4e62a7d12e70c3e68ef539f88db2acf610951fa61f74e2a00eb64ba4faa8eb787b846f57c9a8f791f8ce6774c5b48a212a4244067c33256a0fa'
            '71fcdc8c55f7743ae66dad89ccfadf7650d1a8395f34b2107543a80653924915372e033395e669cb3901eb75b137419a03f3b5b08a5d1a5f27e13a1f5de62a74')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cd pytest-runner-$pkgver
  patch -Np1 -i ../$pkgname-python310.patch
}

build() {
  cd pytest-runner-$pkgver
  python setup.py build
}

check() {
  cd pytest-runner-$pkgver
  python setup.py egg_info
  PYTHONPATH="$PWD" pytest
}

package() {
  cd pytest-runner-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
