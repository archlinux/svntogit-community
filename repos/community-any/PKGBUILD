# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: onny <onny@project-insanity.org>

pkgname=python-passlib
pkgver=1.7.1
pkgrel=4
pkgdesc="A password hashing library for Python"
arch=('any')
url="https://code.google.com/p/passlib/"
license=('custom:BSD')
depends=("python")
optdepends=("python-fastpbkdf2: accelerate PBKDF2-based hashes"
            "python-bcrypt: accelerate Bcrypt hashes"
            "python-scrypt: accelerate SCrypt hashes")
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-bcrypt' 'python-django' 'python-fastpbkdf2' 'python-scrypt')
source=("https://pypi.io/packages/source/p/passlib/passlib-$pkgver.tar.gz")
sha512sums=('3d5f069cd4e44e5e87cdabc46845acbdd6c1eeedb7ce1f611aebee87b0f7af19009b6a47a10ec555fd84260b9f5c933c6429e325d30326de3869f05031674168')

check() {
  export PASSLIB_TEST_MODE=full

  cd "$srcdir"/passlib-$pkgver
  python setup.py nosetests || warning "https://bitbucket.org/ecollins/passlib/issues/98/passlibextdjango-with-django-1112-fails"
}

package() {
  cd passlib-$pkgver
  python setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
