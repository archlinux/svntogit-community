# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jaraco.context
pkgver=3.0.0
pkgrel=1
pkgdesc="Context managers by jaraco"
url="https://github.com/jaraco/jaraco.context"
license=('MIT')
arch=('any')
depends=('python-jaraco' 'python-yg.lockfile')
makedepends=('python-setuptools-scm')
checkdepends=('python-pytest-black' 'python-pytest-checkdocs' 'python-pytest-cov'
              'python-pytest-flake8' 'python-pytest-mypy' 'python-jaraco.test')
source=("https://github.com/jaraco/jaraco.context/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('95143874235fb09dbc6f1922a8916fbbc4282c836a98f7a00547ea75d84a66cd9007b2846e783714e02f83221af3fb5e814db2992fc3243f8807ee406c2d7d78')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cd jaraco.context-$pkgver
  sed -i '/import jaraco.apt/d' jaraco/context.py
  # Ignore flake8 error introduced by the above apt workaround
  echo -e '\nper-file-ignores =\n\tjaraco/context.py: F821' >> .flake8
}

build() {
  cd jaraco.context-$pkgver
  python setup.py build
}

check() {
  cd jaraco.context-$pkgver
  python -m pytest
}

package() {
  cd jaraco.context-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  rm "$pkgdir"/usr/lib/python3.9/site-packages/jaraco/__init__.py \
     "$pkgdir"/usr/lib/python3.9/site-packages/jaraco/__pycache__/__init__.cpython-39.pyc \
     "$pkgdir"/usr/lib/python3.9/site-packages/jaraco/__pycache__/__init__.cpython-39.opt-1.pyc

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
