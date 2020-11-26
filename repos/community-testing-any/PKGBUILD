# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Danilo Bargen <gezuru@gmail.com>
# Contributor: Simon Conseil <contact+aur at saimon dot org>
# Contributor: Jesus Alvarez

pkgname=python-jedi
_gitcommit=3b7106ae71cb7bd3431101d169a0110ee0c179aa
pkgver=0.17.2
pkgrel=3
pkgdesc="Awesome autocompletion for python"
url="https://github.com/davidhalter/jedi"
arch=('any')
license=('MIT')
depends=('python' 'python-parso')
makedepends=('git' 'python-setuptools' 'python-sphinx' 'python-sphinx_rtd_theme')
checkdepends=('python-pytest' 'python-parso')
source=("git+https://github.com/davidhalter/jedi#commit=${_gitcommit}"
        jedi-0.17.2-py39.patch
        git+https://github.com/davidhalter/typeshed
        git+https://github.com/typeddjango/django-stubs)
sha256sums=('SKIP'
            '9b5c13800f29f4c6954d63c0989210cc173162803e8546bfe084a975e3e25208'
            'SKIP'
            'SKIP')

pkgver() {
  cd jedi
  git describe --tags --match 'v*' | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  cd jedi
  git submodule init
  git config submodule."jedi/third_party/typeshed".url "${srcdir}/typeshed"
  git config submodule."jedi/third_party/django-stubs".url "${srcdir}/django-stubs"
  git submodule update --recursive

  # two patches for Python 3.9 cherry-picked from upstream's master branch
  patch -Np1 -i ../jedi-0.17.2-py39.patch
}

build() {
  cd jedi
  python setup.py build
  sphinx-build -b text docs docs/_build/text
  sphinx-build -b man docs docs/_build/man
}

check() {
  cd jedi
  # skip pytest 6 test issues https://github.com/davidhalter/jedi/issues/1660
  # these are also skipped in upstream's Travis CI
  pytest test -k 'not test_completion[pytest'
}

package() {
  cd jedi
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm 644 LICENSE.txt -t "$pkgdir/usr/share/licenses/$pkgname"
  install -Dm 644 CHANGELOG.rst README.rst docs/_build/text/*.txt -t "$pkgdir/usr/share/doc/$pkgname"
  install -Dm 644 docs/_build/man/jedi.1 "$pkgdir/usr/share/man/man1/$pkgname.1"
}

# vim: ts=2 sw=2 et:
